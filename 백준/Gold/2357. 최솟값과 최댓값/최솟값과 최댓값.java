import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

class Node {
    int start,end;
    int min,max;
    Node parent,left,right;
}


public class Main {

    // 하향식 재귀
    static int[] getMinMax(Node p, int[] ans, int a, int b) {
        if (p.start == a && p.end == b) { // 리프 노드
            return new int[]{p.min,p.max};
        }
        if (b <= p.left.end) {
            int[] left = getMinMax(p.left,ans,a,b);
            ans[0] = Math.min(ans[0],left[0]);
            ans[1] = Math.max(ans[1],left[1]);
            return ans;
        } else if (a <= p.left.end && b > p.left.end) {
            int[] left = getMinMax(p.left,ans,a,p.left.end);
            int[] right = getMinMax(p.right,ans,p.right.start,b);
            int min = Math.min(left[0],right[0]);
            int max = Math.max(left[1],right[1]);
            ans[0] = Math.min(ans[0],min);
            ans[1] = Math.max(ans[1],max);
            return ans;
        } else { // 오른쪽에 다 있는 경우
            int[] right = getMinMax(p.right,ans,a,b);
            ans[0] = Math.min(ans[0],right[0]);
            ans[1] = Math.max(ans[1],right[1]);
            return ans;
        }



    }
    static void makeTree(Integer[] arr, Node[] leaf, Node p) {
        int s = p.start;
        int e = p.end;
        if (e==s) { // 리프노드
            p.min = arr[s];
            p.max = arr[s];
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

    static int[] initTreeValue(Node p){
        if (p == null) return new int[]{Integer.MAX_VALUE,Integer.MIN_VALUE};
        if (p.left == null && p.right == null) { // 맨 밑 노드면 중단
            return new int[]{p.min,p.max};
        }
        Node l = p.left;
        Node r = p.right;
        int[] leftArr = initTreeValue(l);
        int[] rightArr = initTreeValue(r);
        p.min = Math.min(leftArr[0],rightArr[0]);
        p.max = Math.max(leftArr[1],rightArr[1]);
        return new int[]{p.min,p.max};
    }

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] tmp = br.readLine().split(" ");
        final int N = Integer.parseInt(tmp[0]);
        final int M = Integer.parseInt(tmp[1]);
        Integer[] arr = new Integer[N+1];
        arr[0] = null;
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        Node[] leaf = new Node[arr.length];
        Node root = new Node();
        root.start = 1;
        root.end = arr.length-1;
        makeTree(arr,leaf,root);
        initTreeValue(root);
        for (int i = 0; i < M; i++) {
            tmp = br.readLine().split(" ");
            int a = Integer.parseInt(tmp[0]);
            int b = Integer.parseInt(tmp[1]);
            int[] ans = {Integer.MAX_VALUE, Integer.MIN_VALUE};
            int[] minmax = getMinMax(root,ans,a,b);
            bw.write(minmax[0]+" "+minmax[1]+"\n");
        }
        bw.flush();

    }

}
