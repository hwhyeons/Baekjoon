import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] KAndN = br.readLine().split(" ");
        final int K = Integer.parseInt(KAndN[0]);
        final int N = Integer.parseInt(KAndN[1]);
        ArrayList<Long> arr = new ArrayList<>();
        for (int i = 0; i < K; i++) {
            arr.add(Long.parseLong(br.readLine()));
        }

        final long MAX = Collections.max(arr);
        long n = 0;
        n = arr.stream().mapToLong(num -> num / MAX).sum(); // 처음에는 최대값으로 테스트
        if (n >= N) { // 혹시 맨처음거에서 끝나는 경우
            System.out.println(MAX);
            return;
        }
        long start = 1;
        long end = MAX;
        long mid = -1;
        long answerCM = -1;
        while (start <= end) {
            mid = (start+end)/2;
            long finalMid = mid;
            n = arr.stream().mapToLong(num -> num / finalMid).sum();
            if (n < N) {
                end = mid-1;
            } else {
                answerCM = Math.max(answerCM,mid);
                start = mid+1;
            }
        }
        System.out.println(answerCM);
    }
}