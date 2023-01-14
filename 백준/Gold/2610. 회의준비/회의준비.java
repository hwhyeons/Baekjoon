import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

class Node {
    boolean visited = false;
    public ArrayList<Integer> next = new ArrayList<>(); // 인접 노드
}

public class Main{


    static int PEOPLE;
    static Node[] nodes;
    static int[][] dist;
    static int INF = 10000000;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PEOPLE = Integer.parseInt(br.readLine());
        int relationCount = Integer.parseInt(br.readLine());
        nodes = new Node[PEOPLE+1];
        dist = new int[PEOPLE+1][PEOPLE+1];
        for (int i = 1; i < nodes.length; i++) {
            nodes[i] = new Node();
        }
        for (int i = 0; i < relationCount; i++) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(stk.nextToken());
            int b = Integer.parseInt(stk.nextToken());
            if (nodes[a].next.contains(b)) continue;
            else nodes[a].next.add(b);
            if (nodes[b].next.contains(a)) continue;
            else nodes[b].next.add(a);
            dist[a][b] = 1;
            dist[b][a] = 1;
        }

        ArrayList<ArrayList<Integer>> group = new ArrayList<>();
        for (int i = 1; i < nodes.length; i++) {
            if (nodes[i].visited) continue;
            ArrayList<Integer> committeeMember = new ArrayList<>();
            committeeMember.add(i);
            dfs(i,committeeMember);
            group.add(committeeMember);
        }

        int committeeCount = group.size();
        ArrayList<Integer> masters = new ArrayList<>(); // 위원회 대표 인덱스

        // 각 위원회마다 대표 선출
        for (int i = 1; i < dist.length; i++) {
            for (int j = 1; j < dist.length; j++) {
                if (i == j) continue;
                if (dist[i][j] == 1) continue;
                else dist[i][j] = INF;
            }
        }
        floydWarshall();

        for (ArrayList<Integer> committeeMember : group) {
            // 각 위원회 멤버들끼리 거리 비교
            int masterIndex = getMasterIndex(committeeMember);
            masters.add(masterIndex);
        }
        Collections.sort(masters);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(committeeCount+"\n");
        for (int i = 0; i < masters.size(); i++) {
            bw.write(masters.get(i)+"\n");
        }
        bw.flush();
    }

    public static int go(int startIndex, int finalIndex, int depth) {
        if (startIndex == finalIndex) return depth;
        nodes[startIndex].visited = true;
        ArrayList<Integer> friends = nodes[startIndex].next;
        int min = INF;
        for (int i = 0; i < friends.size(); i++) {
            if (nodes[friends.get(i)].visited) continue;
            if (startIndex == friends.get(i)) continue;
            min = Math.min(min,go(friends.get(i),finalIndex,depth+1));
        }
        return min;
    }

    public static void floydWarshall() {
        for (int k = 1; k <= PEOPLE; k++) {
            for (int i = 1; i <= PEOPLE; i++) {
                for (int j = 1; j <= PEOPLE; j++) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    public static int getMasterIndex(ArrayList<Integer> committeeMember) {
//        for (int i = 0; i < committeeMember.size(); i++) {
//            int m1 = committeeMember.get(i);
//            for (int j = 0; j < committeeMember.size(); j++) {
//                int m2 = committeeMember.get(j);
//                if (m1 == m2) continue; // ex : m1 = 5 / m2 = 7
//                if (dist[m1][m2] != INF || dist[m2][m1] != INF) continue;
//                // visited clear
//                committeeMember.stream().forEach(memberIdx->nodes[memberIdx].visited = false);
//                int minDist = go(m1,m2,0);
//                dist[m1][m2] = minDist;
//                dist[m2][m1] = minDist;
//            }
//        }
        int[] maxArr = new int[committeeMember.size()];
        Arrays.fill(maxArr,Integer.MIN_VALUE);
        for (int i = 0; i < committeeMember.size(); i++) {
            for (int j = 0; j < committeeMember.size(); j++) {
                if (i == j) continue;
                if (dist[committeeMember.get(i)][committeeMember.get(j)] == INF) continue;
                maxArr[i] = Math.max(maxArr[i],dist[committeeMember.get(i)][committeeMember.get(j)]);
            }
        }
        int minIndex = 0;
        for (int i = 0; i < maxArr.length; i++) {
            if (maxArr[i] < maxArr[minIndex]) minIndex = i;
        }
        return committeeMember.get(minIndex);
    }



    public static void dfs(int index,ArrayList<Integer> committeeMember) {
        nodes[index].visited = true;
        ArrayList<Integer> friend = nodes[index].next;
        for (int friendIndex : friend) {
            if (nodes[friendIndex].visited) continue;;
            committeeMember.add(friendIndex);
            dfs(friendIndex,committeeMember);
        }
    }
}