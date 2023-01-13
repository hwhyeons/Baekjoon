import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
    static char[] arr;
    static int idx = 0;
    static boolean error = false;
    static boolean[] visited;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        arr = br.readLine().toCharArray();
        int ans = 0;
        visited = new boolean[arr.length];
        int l2 =0,l1=0,r1=0,r2=0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == '(') l1++;
            if (arr[i] == ')') l2++;
            if (arr[i] == '[') r1++;
            if (arr[i] == ']') r2++;
        }
        if (l1 != l2 || r1 != r2) {
            System.out.println(0);
            return;
        }
        for (int i = 0; i < arr.length; i++) {
            if (visited[i]) continue;
            if (error) break;
            ans += f(i);
        }
        if (error) System.out.println(0);
        else System.out.println(ans);
    }

    private static int f(int idx) {
        if (idx >= arr.length) {
            return 0;
        } else if (error) {
            return -1;
        }
        visited[idx] = true;
        char c=  arr[idx];
        if (c == ')') return 2;
        if (c == ']') return 3;
        int sum = 0;
        for (int i = idx+1; i < arr.length; i++) {
            if (visited[i]) continue;
            if (c == '(' && arr[i] == ')') {
                visited[i] = true;
                return sum == 0 ? 2: 2*sum;
            } else if (c == '[' && arr[i] == ']') {
                visited[i] = true;
                return sum == 0 ? 3 : 3*sum;
            } else {
                if (c == '(' && arr[i] == ']') {
                    error = true;
                    return -1;
                } else if (c == '[' && arr[i] == ')') {
                    error = true;
                    return -1;
                }
                sum += f(i);
            }
        }
        if (c == '(') {
            return 2*sum;
        } else {
            return 3*sum;
        }
    }
}