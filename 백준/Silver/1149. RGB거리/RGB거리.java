import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main{

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int COUNT = Integer.parseInt(br.readLine());
        int[][] org = new int[COUNT][3];
        int[][] sum = new int[COUNT][3];
        for (int i = 0; i < COUNT; i++) {
            StringTokenizer stk  = new StringTokenizer(br.readLine());
            org[i][0] = Integer.parseInt(stk.nextToken());
            org[i][1] = Integer.parseInt(stk.nextToken());
            org[i][2] = Integer.parseInt(stk.nextToken());
        }
        // 첫번째 인덱스만 미리 설정
        sum[0][0] = org[0][0];
        sum[0][1] = org[0][1];
        sum[0][2] = org[0][2];

        for (int i = 1; i < COUNT; i++) {
            sum[i][0] = Math.min(sum[i-1][1],sum[i-1][2])+org[i][0];
            sum[i][1] = Math.min(sum[i-1][0],sum[i-1][2])+org[i][1];
            sum[i][2] = Math.min(sum[i-1][0],sum[i-1][1])+org[i][2];
        }

        int last = COUNT-1;
        System.out.println(Math.min(Math.min(sum[last][0],sum[last][1]),sum[last][2]));

    }
}