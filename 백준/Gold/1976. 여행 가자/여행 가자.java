import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Node {
    int groupNumber = -1;
    ArrayList<Integer> friends = new ArrayList<>();
}
public class Main{

    static void makeGroup(Node n) {
        n.groupNumber = groupNumber;
        var friends = n.friends;
        for (int fidx : friends) {
            if (nodes[fidx].groupNumber == -1) makeGroup(nodes[fidx]);
        }
    }

    static int groupNumber = 0;
    static Node[] nodes;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cityCount = Integer.parseInt(br.readLine());
        int connectCount = Integer.parseInt(br.readLine());
        nodes = new Node[cityCount+1];
        for (int i = 1; i <= cityCount; i++) {
            String[] tmp = br.readLine().split(" ");
            Node n = new Node();
            for (int j = 0; j < tmp.length; j++) {
                if (tmp[j].equals("1")) {
                    n.friends.add(j+1);
                }
            }
            nodes[i] = n;
        }
        int[] wantTrip = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        for (int i = 1; i <= cityCount; i++) {
            if (nodes[i].groupNumber == -1) {
                makeGroup(nodes[i]);
                groupNumber++;
            }
        }


        int g = nodes[wantTrip[0]].groupNumber;
        for (int i = 1; i < wantTrip.length; i++) {
            if (nodes[wantTrip[i]].groupNumber != g) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}