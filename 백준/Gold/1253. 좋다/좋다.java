import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] arr;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).sorted().toArray();
        int answer = 0;
        int num;
        for (int i = 0; i < arr.length; i++) {
            num = arr[i];
            int start = 0;
            int end = arr.length-1;
            int sum;
            while (start < end) {
                sum = arr[start] + arr[end];
                if (start == i) {
                    start++;
                    continue;
                } else if (end == i) {
                    end--;
                    continue;
                }
                if (sum == num) {
                    answer++;
                    break;
                } else if (sum < num) {
                    start++;
                } else {
                    end--;
                }
            }
        }
        System.out.println(answer);
    }
}