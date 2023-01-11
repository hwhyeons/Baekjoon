import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;

public class Main{

    static int mod = 1000000000;
    static HashMap<Integer,int[]> map = new HashMap<>();
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long answer = 0;
        for (int i = 1; i <= 9; i++) {
//            System.out.println(g(N,i));
            answer += g(N,i)%mod;
        }
        System.out.println(answer%mod);
    }

    private static int g(int n, int i){
        if (n==0) return 0;
        if (i ==-1 || i == 10) return 0;
        if (n==1) return 1;
        if (map.containsKey(n) && map.get(n)[i] != -1) {
            return map.get(n)[i];
        }

        int sum = 0;
        sum = (g(n-1,i+1)%mod + g(n-1,i-1)%mod)%mod;
        if (map.containsKey(n)) {
            int[] tmp = map.get(n);
            tmp[i] = sum;
        } else {
            int[] tmp = new int[10];
            Arrays.fill(tmp, -1);
            tmp[i] = sum;
            map.put(n,tmp);
        }
        return sum;
    }
}