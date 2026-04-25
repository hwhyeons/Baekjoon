import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int TEST_CASE_COUNT = Integer.parseInt(br.readLine());
        final int[] arr = {0,1,2,4,7,13,24,44,81,149,274,504};
        for (int i = 0; i < TEST_CASE_COUNT; i++) {
            bw.write(arr[Integer.parseInt(br.readLine())]+"\n");
        }
        bw.flush();
    }
}
