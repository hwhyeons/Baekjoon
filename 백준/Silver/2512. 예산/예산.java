import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int count = Integer.parseInt(br.readLine());
        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).sorted().toArray();
        final int budget = Integer.parseInt(br.readLine()); // 예산
        final int max = arr[arr.length-1];
        final int sumAll = Arrays.stream(arr).sum();
        if (sumAll <= budget) {
            System.out.println(max);
            return;
        }

        int startMoney = 1;
        int endMoney = max;
        int midMoney; // 상한 금액
        int sum;
        int answer = 1;
        while (startMoney <= endMoney) {
            sum = 0;
            midMoney = (startMoney+endMoney)/2;
            for (int i = 0; i < arr.length; i++) {
                sum = sum + (arr[i] <= midMoney ? arr[i] : midMoney);
            }
            if (sum <= budget) { // 예산 안으로 해결 될 때
                answer = Math.max(answer,midMoney);
                startMoney = midMoney+1;
            } else {
                endMoney = midMoney-1;
            }
        }
        System.out.println(answer);
    }
}