import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    static int N;
    public static void main(String[] l) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int N = Integer.parseInt(br.readLine());
        Main.N = N;
        final String NString = Integer.toString(N);
        int minDigit = 1;
        int nine = 9,tmp;
        for (int i = 0; i <= NString.length(); i++) { // 예를 들어 n이 9999로 4자리면, 생성자가 5자리가 될 수는 없음
            tmp = nine+minDigit*9;
            if (N > tmp) {
                nine = nine + (nine << 3) + (nine << 1); // tmp = 9 + 9*2+9*8
                minDigit++;
            } else break;
        }

        int ans = 0;
        int startValue = minDigit == 1 ? 0 : (int)Math.pow(10,minDigit-1);
        for (int i = startValue; i < N; i++) {
            if (isConstructor(i)) {
                ans = i;
                break;
            }
        }
        System.out.println(ans);
    }

    private static boolean isConstructor(int k) {
        int digit = Integer.toString(k).length();
        int ans = k;
        int t1;
        int t2;
        for (int i = 0; i < digit; i++) {
            t1 = 1;
            t2 = 1;
            for (int j = 0; j < digit-i; j++) {
                t1 = t1*10;
            }
            for (int j = 0; j < digit-i-1; j++) {
                t2 = t2*10;
            }
            ans += (k%t1)/t2;
        }
        return ans == N;
    }
}