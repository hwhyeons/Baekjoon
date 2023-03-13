import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

class Node {
    int start,end;
    long value;
    Node parent,left,right;
}


public class Main {
    static void update(Node p,long gapBefore) {
        long before = p.value;
        p.value+=gapBefore;
        if (p.parent != null) {
            update(p.parent,p.value-before);
        }
    }
    static void updateTree(Node leaf, long newValue) {
        long gap = newValue-leaf.value;
        leaf.value = newValue;
        if (leaf.parent != null) {
            update(leaf.parent,gap);
        }
    }
    static void makeTree(Integer[] arr, Node[] leaf, Node p) {
        int s = p.start;
        int e = p.end;
        if (e==s) { // 리프노드
            p.value = arr[s];
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

    static long initTreeValue(Node p){
        if (p == null) return 0;
        if (p.left == null && p.right == null) { // 맨 밑 노드면 중단
            return p.value;
        }
        Node l = p.left;
        Node r = p.right;
        p.value = initTreeValue(l) + initTreeValue(r);
        return p.value;
    }

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        final int[] stmp = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        final int N = stmp[0];
        final int Q = stmp[1];
        Integer[] arr = new Integer[N+1];
        arr[0] = null;
        StringTokenizer stk = new StringTokenizer(br.readLine());
        for (int i = 1; i < arr.length; i++) {
            arr[i] = Integer.parseInt(stk.nextToken());
        }
        Node[] leaf = new Node[arr.length];
        Node root = new Node();
        root.start = 1;
        root.end = arr.length-1;
        makeTree(arr,leaf,root);
        initTreeValue(root);
        for (int i = 0; i < Q; i++) {
            StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(stringTokenizer.nextToken());
            int y = Integer.parseInt(stringTokenizer.nextToken());
            if (x > y) {
                int tmp = x;
                x = y;
                y = tmp;
            }
            long acc = getPartitionAcc(root,x,y);
            bw.write(Long.toString(acc)+"\n");
            int a = Integer.parseInt(stringTokenizer.nextToken());
            int b = Integer.parseInt(stringTokenizer.nextToken());
            updateTree(leaf[a],b);
        }
        bw.flush();
    }

    private static long getPartitionAcc(Node p,int x, int y) {
        if (p.start == x && p.end == y) {
            return p.value;
        }
        if (y <= p.left.end) {
            return getPartitionAcc(p.left,x,y);
        } else if (x <= p.left.end && y > p.left.end) {
            return getPartitionAcc(p.left,x,p.left.end) + getPartitionAcc(p.right,p.right.start,y);
        } else { // 오른쪽에 다 있는 경우
            return getPartitionAcc(p.right,x,y);
        }
    }
}