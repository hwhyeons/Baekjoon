import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;


public class Main{

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int N = Integer.parseInt(br.readLine());
        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int max = Integer.MIN_VALUE;
        int last = arr[arr.length-1];
        int[] sum0 = new int[arr.length]; // 짝수
        int[] sum1 = new int[arr.length]; // 홀수
        sum0[0] = arr[0];
        // 합을 미리 계산
        for (int i = 1; i < arr.length; i++) {
            if (i%2 == 0) { // 짝수
                sum0[i] = sum0[i-1] + arr[i];
                sum1[i] = sum1[i-1];
            } else { // 홀수
                if (i == 1) { // 1만 따로 처리
                    sum0[1] = sum0[0];
                    sum1[1] = arr[1];
                } else {
                    sum0[i] = sum0[i-1]; // 짝수는 그대로
                    sum1[i] = sum1[i-1] + arr[i];
                }
            }
        }
        sum1[arr.length-1] = 0; // 홀수 맨마지막은 따로 연산할 것


        // 하나씩 다 해보기
        max = sum0[arr.length-1]; // 일단 밑장 안빼는 경우 : 전부 짝수 카드 얻는 경우
        max = Math.max(max,sum1[arr.length-2]+last); // 0번째에서 밑장 빼는 경우 : 정훈이 전부 홀수 인덱스
        for (int i = 0; i< arr.length-1; i++) { // i = 밑장빼기 카드시점
            // 정훈이만 계산
            int jungHoon = sum0[i] + sum1[arr.length-2] - sum1[i];
            if (i % 2 != 0) { // i가 홀수면 last추가
                jungHoon += last;
            }
            max = Math.max(max,jungHoon);
        }
        System.out.println(max);
    }
}