import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        HashSet<String> set = new HashSet<>();
        for (int i = 0; i < N; i++) {
            set.add(st.nextToken());
        }
        int K =Integer.parseInt(br.readLine());
        System.out.println(String.join(" ",Arrays.stream(br.readLine().split(" ")).map((str) -> set.contains(str) ? "1" : "0").toArray(String[]::new)));
    }
}