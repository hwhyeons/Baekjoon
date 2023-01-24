import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;
import java.util.stream.Collectors;


class Node {
    int nodeNumber;
    ArrayList<Node> friend = new ArrayList<>();
    ArrayList<Integer> vals = new ArrayList<>();
}


public class Main{
    static Node[] nodes;
//    static boolean[] visited;

    static HashMap<Integer,Integer> map = new HashMap<>(); // 노드 번호 / 값
    static HashMap<Integer,Integer> map2 = new HashMap<>(); // 노드 번호 / 직전 노드

    private static int f(int nodeNumber) {
        if (map.containsKey(nodeNumber)) {
            return map.get(nodeNumber);
        }
        ArrayList<Node> friends = nodes[nodeNumber].friend;
        ArrayList<Integer> vals = nodes[nodeNumber].vals;
        int max = Integer.MIN_VALUE;
        int maxFNumber = -1;
        int c = -1;
        if (friends.isEmpty()) {
            return 0;
        }

        for (int i = 0; i < friends.size(); i++) {
            int fnumber = friends.get(i).nodeNumber;
            if (fnumber == 1) {
                c = vals.get(i);
            } else {
                c = vals.get(i)+f(fnumber);
            }
            if (c > max) {
                max = c;
                maxFNumber = fnumber;
            }
        }
        map.put(nodeNumber,max);
        map2.put(nodeNumber,maxFNumber);
        return max;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        final int NODE_COUNT = Integer.parseInt(br.readLine());
        final int EDGE_COUNT = Integer.parseInt(br.readLine());
        nodes = new Node[NODE_COUNT+1];
//        visited = new boolean[NODE_COUNT+1];

        for (int i = 1; i <= NODE_COUNT; i++) {
            Node n = new Node();
            n.nodeNumber = i;
            nodes[i] = n;
        }
        for (int i = 0; i < EDGE_COUNT; i++) {
            String[] tmp = br.readLine().split(" ");
            int start = Integer.parseInt(tmp[0]);
            int end = Integer.parseInt(tmp[1]);
            int val = Integer.parseInt(tmp[2]);
            nodes[end].friend.add(nodes[start]);
            nodes[end].vals.add(val);
        }
        int n = f(1);
        bw.write(n+"\n");
        ArrayList<Integer> answers = new ArrayList<>();
        answers.add(1);
        int idx = 1;
        while (true) {
            idx = map2.get(idx);
            if (idx == 1) break;
            answers.add(idx);
        }
        bw.write("1 ");
        for (int i = answers.size()-1; i >= 0; i--) {
            bw.write(answers.get(i)+" ");
        }
        bw.flush();
    }
}