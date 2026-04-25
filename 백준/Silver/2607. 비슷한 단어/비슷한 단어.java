import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.stream.IntStream;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int COUNT = Integer.parseInt(br.readLine());
        int[] org = new int[26]; // 0 : 'A
        br.readLine().chars().map(c->c-'A').forEach(c->org[c]+=1); // 'A'아스키 코드 값을 빼서 'A'를 0번 인덱스로 만들어줌
        int answer = 0;
        for (int i = 0; i < COUNT-1; i++) {
            int[] tmp = new int[26];
            br.readLine().chars().map(c->c-'A').forEach(c->tmp[c]+=1);
            boolean ok = true;
            int sum = 0;
            int diffCount = 0;
            for (int j = 0; j < 26; j++) {
                int gap = org[j]-tmp[j];
                if (Math.abs(gap) >= 2) { // 차이가 2이상이면 불가능
                    ok = false;
                    break;
                }
                sum += gap;
                if (Math.abs(gap) == 1){
                    ++diffCount;
                    if (diffCount>=3) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                if (Math.abs(sum) <= 1) answer++;
            }
        }
        System.out.println(answer);
    }
}