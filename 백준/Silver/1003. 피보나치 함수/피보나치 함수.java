import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws Exception {
        StringBuilder out = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] inputList = br.lines().limit(Integer.parseInt(br.readLine())).mapToInt(Integer::parseInt).toArray();
        int max = Arrays.stream(inputList).max().getAsInt();
        int[][] f = new int[max+1][2]; // 1부터 max까지  / 0번인덱스는 0 횟수, 1번 인덱스는 1 횟수
        if (max ==0) {
            System.out.println("1 0");
            return;
        }
        f[0][0] = f[1][1] = 1;
        for (int i = 2; i <= max; i++) {
            f[i][0] = f[i-1][0] + f[i-2][0];
            f[i][1] = f[i-1][1] + f[i-2][1];
        }
        for (int i : inputList) {
            out.append(f[i][0] + " " + f[i][1] + "\n");
        }
        System.out.println(out.toString());
    }
}