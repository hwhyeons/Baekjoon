import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static ArrayList<Integer> arr = new ArrayList<>();
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] readString = br.readLine().split(" ");
        final int N = Integer.parseInt(readString[0]);
        int M = Integer.parseInt(readString[1]); // 인출 횟수
        for (int i = 0; i < N; i++) {
            arr.add(Integer.parseInt(br.readLine()));
        }
        final int minInArr = Collections.max(arr); // 최대 값보다는 많이 뽑아야한다 (예를 들어 일주일 동안 사용할 금액 중에 가장 큰 값이 80원이면, 그보다 적은 70원을 뽑게되면 무한 루프 발생)


        int minMoney = 1000000000; // 최소 인출 금액
        int startMoney = minInArr;
        int endMoney = minMoney;
        int midMoney;
        int withDrawCount;
        while (startMoney <= endMoney) {
            midMoney = (startMoney+endMoney)/2;
            withDrawCount = getWithDrawCount(midMoney);
            // 인출 횟수가 줄어들 수록 한번에 인출할 금액 증가
            if (withDrawCount <= M) { // 의도한 인출 횟수가 나와도, 금액을 최대한 줄여야 한다
                minMoney = Math.min(minMoney,midMoney);
                endMoney = midMoney - 1;
            } else { // 인출 횟수가 많으므로, 인출 금액을 늘린다
                startMoney = midMoney + 1;
            }
        }
        System.out.println(minMoney);
    }

    private static int getWithDrawCount(final int withDrawMoney) {
        int currentMoney = withDrawMoney;
        int withDrawCount = 1; // 출금 횟수
        int todayUseMoney; // 오늘 사용할 돈
        for (int i = 0; i < arr.size(); i++) {
            todayUseMoney = arr.get(i);
            if (currentMoney - todayUseMoney < 0) {
                withDrawCount++;
                currentMoney = withDrawMoney - todayUseMoney;
            } else {
                currentMoney = currentMoney - todayUseMoney;
            }
        }
        return withDrawCount;
    }
}