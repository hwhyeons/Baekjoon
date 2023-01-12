import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main{

    private static BigInteger f(int n){
        BigInteger ans = new BigInteger("1");
        for (int i = 1; i <= n; i++) {
            ans = ans.multiply(new BigInteger(Integer.toString(i)));
        }
        return ans;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCount = Integer.parseInt(br.readLine());
        for (int i = 0; i < testCount; i++) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(stk.nextToken());
            int n = Integer.parseInt(stk.nextToken());
            System.out.println(f(n).divide(f(r).multiply(f(n-r))));
        }
    }
}