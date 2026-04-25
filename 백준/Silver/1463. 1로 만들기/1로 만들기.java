import java.io.*;

public class Main {
    static int answer = Integer.MAX_VALUE;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int num = Integer.parseInt(br.readLine());
        go(num,0);
        System.out.println(answer);
    }

    private static void go(int n, int count) {
        if (n <= 1) {
            if (n == 1) answer = Math.min(answer,count);
            return;
        } else if (count >= answer) {
            return;
        }
        if (n % 3 == 0) {
            go(n/3,count+1);
        }
        if (n % 2 == 0) {
            go(n/2,count+1);
        }
        go(n-1,count+1);
    }
}
