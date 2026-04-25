import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCaseCount = Integer.valueOf(br.readLine());
        int[] arr;
        for (int i = 0; i < testCaseCount; i++) {
            arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).sorted().skip(1).limit(3).toArray();
            System.out.println(arr[2] - arr[0] >= 4 ? "KIN" : Integer.toString(arr[0] + arr[1] + arr[2]));
        }
    }
}