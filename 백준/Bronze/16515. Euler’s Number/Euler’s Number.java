import java.io.*;
import java.util.*;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int N = Integer.parseInt(br.readLine());
        double start = 1.0;
        double sum = 1.0;
        for (int i = 1; i <= N; i++) {
            start = start/i;
            sum = sum + start;
        }
        System.out.println(sum);
    }
}
