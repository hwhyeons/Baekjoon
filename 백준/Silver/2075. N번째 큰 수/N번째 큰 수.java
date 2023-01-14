import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int N = Integer.parseInt(br.readLine());
        int[][] arr = new int[N][N];
        int[] lineIndex = new int[N];
        Arrays.fill(lineIndex,N-1);
        for (int i = 0; i < N; i++) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(stk.nextToken());
            }
        }

        int max = 0;
        for (int i = 1; i <= N; i++) {
            max = Integer.MIN_VALUE;
            int maxIndex = -1;
            for (int j = 0; j < N; j++) {
                if (lineIndex[j] >= 0 && max < arr[lineIndex[j]][j]) {
                    max = arr[lineIndex[j]][j];
                    maxIndex = j;
                }
            }
            lineIndex[maxIndex] -= 1;
        }
        System.out.println(max);
    }
}