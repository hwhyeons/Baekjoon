import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        HashSet<Integer> set = new HashSet<>();
        while (st.hasMoreElements()) {
            set.add(Integer.parseInt(st.nextToken()));
        }
        final int sum = Integer.parseInt(br.readLine());
        int answer = set.stream().filter(key -> set.contains(sum-key)).toArray().length;
        System.out.println(answer/2);
    }
}