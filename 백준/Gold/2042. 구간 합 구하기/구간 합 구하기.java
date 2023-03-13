import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

class Node {
    int start,end;
    BigInteger value;
    Node parent,left,right;
}


public class Main {
    static void update(Node p,BigInteger gapBefore) {
        var before = p.value;
        p.value = p.value.add(gapBefore);
        if (p.parent != null) {
            update(p.parent,p.value.subtract(before));
        }
    }
    static void updateTree(Node leaf, Long newValue) {
        BigInteger gap = new BigInteger(Long.toString(newValue)).subtract(leaf.value);
        leaf.value = new BigInteger(Long.toString(newValue));
        if (leaf.parent != null) {
            update(leaf.parent,gap);
        }
    }
    static void makeTree(Long[] arr, Node[] leaf, Node p) {
        int s = p.start;
        int e = p.end;
        if (e==s) { // 리프노드
            p.value = new BigInteger(Long.toString(arr[s]));
            leaf[s] = p;
            return;
        }
        int half = (e-s)/2+s;
        Node leftChild = new Node();
        Node rightChild = new Node();
        leftChild.start = p.start;
        leftChild.end = half;
        leftChild.parent = p;
        rightChild.start = half+1;
        rightChild.end = p.end;
        rightChild.parent = p;
        p.left = leftChild;
        p.right = rightChild;
        makeTree(arr,leaf,leftChild);
        makeTree(arr,leaf,rightChild);
    }

    static BigInteger initTreeValue(Node p){
        if (p == null) return BigInteger.ZERO;
        if (p.left == null && p.right == null) { // 맨 밑 노드면 중단
            return p.value;
        }
        Node l = p.left;
        Node r = p.right;
        p.value = initTreeValue(l).add(initTreeValue(r));
        return p.value;
    }

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        final int[] stmp = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        final int N = stmp[0];
        final int M = stmp[1];
        final int K = stmp[2];
        Long[] arr = new Long[N+1];
        arr[0] = null;
        for (int i = 1; i <= N; i++) {
            arr[i] = Long.parseLong(br.readLine());
        }
        Node[] leaf = new Node[arr.length];
        Node root = new Node();
        root.start = 1;
        root.end = arr.length-1;
        makeTree(arr,leaf,root);
        initTreeValue(root);
        for (int i = 0; i < M+K; i++) {
            StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
            int a,b;
            long c;
            a = Integer.parseInt(stringTokenizer.nextToken());
            b = Integer.parseInt(stringTokenizer.nextToken());
            c = Long.parseLong(stringTokenizer.nextToken());

            if (a == 1) {
                updateTree(leaf[b],c);
            } else if (a == 2) {
                String acc = getPartitionAcc(root,b,(int)c).toString();
                bw.write(acc+"\n");
            }
        }
        bw.flush();
    }

    private static BigInteger getPartitionAcc(Node p,int x, int y) {
        if (p.start == x && p.end == y) {
            return p.value;
        }
        if (y <= p.left.end) {
            return getPartitionAcc(p.left,x,y);
        } else if (x <= p.left.end && y > p.left.end) {
            return getPartitionAcc(p.left,x,p.left.end).add(getPartitionAcc(p.right,p.right.start,y));
        } else { // 오른쪽에 다 있는 경우
            return getPartitionAcc(p.right,x,y);
        }
    }
}