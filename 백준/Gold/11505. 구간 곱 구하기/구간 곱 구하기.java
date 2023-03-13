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
    static int divide = 1000000007;
    static void update(Node p) {
        long leftValue = p.left != null ? p.left.value : 1;
        long rightValue = p.right != null ? p.right.value : 1;
        p.value = ((leftValue%divide)*(rightValue%divide))%divide;
        if (p.parent != null) {
            update(p.parent);
        }
    }

    static void updateTree(Node leaf, long newValue) {
        leaf.value = newValue;
        if (leaf.parent != null) {
            update(leaf.parent);
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
        p.value = ((initTreeValue(l)%divide) * (initTreeValue(r)%divide))%divide;
        return p.value;
    }

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        final int[] stmp = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        final int N = stmp[0];
        final int M = stmp[1];
        final int K = stmp[1];
        Integer[] arr = new Integer[N+1];
        arr[0] = null;
        for (int i = 1; i < arr.length; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        Node[] leaf = new Node[arr.length];
        Node root = new Node();
        root.start = 1;
        root.end = arr.length-1;
        makeTree(arr,leaf,root);
        initTreeValue(root);
        for (int i = 0; i < M+K; i++) {
            StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
            int a,b,c;
            a = Integer.parseInt(stringTokenizer.nextToken());
            b = Integer.parseInt(stringTokenizer.nextToken());
            c = Integer.parseInt(stringTokenizer.nextToken());
            if (a == 1) {
                updateTree(leaf[b],c);
            } else {
                long ans = getPartitionMultiply(root,b,c);
                bw.write(ans+"\n");
            }
        }
        bw.flush();
    }

    private static long getPartitionMultiply(Node p,int x, int y) {
        if (p.start == x && p.end == y) {
            return p.value;
        }
        if (y <= p.left.end) {
            return getPartitionMultiply(p.left,x,y);
        } else if (x <= p.left.end && y > p.left.end) {
            return (getPartitionMultiply(p.left,x,p.left.end)%divide * getPartitionMultiply(p.right,p.right.start,y)%divide)%divide;
        } else { // 오른쪽에 다 있는 경우
            return getPartitionMultiply(p.right,x,y);
        }
    }
}

