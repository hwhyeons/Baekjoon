import java.io.*;
import java.util.Arrays;


public class Main {
    static int[][] arr;
    static int white = 0,blue =0,N;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = br.lines().map(line-> Arrays.stream(line.split(" ")).mapToInt(Integer::parseInt).toArray()).toArray(int[][]::new);
        f(0,0,N);
        System.out.println(white+"\n"+blue);
    }
    private static void f(int x1,int y1, int len) {
        int color = arr[y1][x1];
        // 전부 같은 색
        boolean ok = true;
        loop:
        for (int i = y1; i < y1+len; i++) {
            for (int j = x1; j < x1+len; j++) {
                if (arr[i][j] != color){
                    ok = false;
                    break loop;
                }
            }
        }
        if (ok) {
            if (color == 0) ++white;
            else ++blue;
            return;
        }
        int nextLen = len/2;
        f(x1,y1,nextLen);
        f(x1 + nextLen, y1, nextLen);
        f(x1,y1+nextLen,nextLen);
        f(x1 + nextLen, y1 + nextLen,nextLen);
    }
}