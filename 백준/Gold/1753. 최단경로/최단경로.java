import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Friend {
    Node node;
    int dist;
}

class Node {
    int index;
    ArrayList<Node> f = new ArrayList<>();
    ArrayList<Integer> fDist = new ArrayList<>();
}

public class Main{

    static int inf = 5000000;

    // 이건 모든 노드에서의 최소 거리가 아니라, 특정 노드에서 나머지 노드에서만 고려하는 것
    // 다른 노드까지 따질려면 이 dijkstra 메소드를 모든 노드 만큼 호출해주면 된다
    private static void dijkstra(Node node, int V) {
        int[] mins = new int[V];
        Arrays.fill(mins,inf);
        PriorityQueue<Friend> pq = new PriorityQueue<>(Comparator.comparingInt(f->f.dist)); // 인접노드의 거리 순으로 정렬
        Friend me = new Friend();
        me.dist = 0;
        me.node = node;
        pq.add(me);
        mins[node.index] = 0;
        while (!pq.isEmpty()) {
            Friend n = pq.poll();
            int currentIndex = n.node.index;
            ArrayList<Node> f = n.node.f; // 인접 노드
            for (int i = 0; i < f.size(); i++) {
                int fDist = n.node.fDist.get(i);
                int fidx = f.get(i).index;
                if (mins[currentIndex] + fDist < mins[fidx]) {
                    Friend f2 = new Friend();
                    f2.node = f.get(i);
                    f2.dist = mins[currentIndex] + fDist;
                    pq.add(f2);
                    mins[fidx] = mins[currentIndex] + fDist;
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < mins.length; i++) {
            if (mins[i] == inf) {
                sb.append("INF\n");
            } else {
                sb.append(mins[i]+"\n");
            }
        }
        System.out.println(sb.toString());
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        int V = Integer.parseInt(tmp[0]);
        int E = Integer.parseInt(tmp[1]);
        int startNode = Integer.parseInt(br.readLine());
        Node[] nodes = new Node[V];
        for (int i = 0; i < V; i++) {
            nodes[i] = new Node();
            nodes[i].index = i;
        }
        for (int i = 0; i < E; i++) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(stk.nextToken())-1;
            int to = Integer.parseInt(stk.nextToken())-1;
            int weight = Integer.parseInt(stk.nextToken());
            nodes[from].f.add(nodes[to]);
            nodes[from].fDist.add(weight);
        }

        dijkstra(nodes[startNode-1],V);

    }
}