import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder answer = new StringBuilder();
        String[] s1 = br.readLine().split(" ");
        final int K = Integer.parseInt(s1[0]);
        final int L = Integer.parseInt(s1[1]);
        LinkedHashSet<String> set = new LinkedHashSet<>();
        for (int i = 0; i < L; i++) {
            String s = br.readLine();
            if (set.contains(s)) {
                set.remove(s);
            }
            set.add(s);
        }
        set.stream().limit(K).forEach(t-> answer.append(t).append("\n"));
        System.out.println(answer);
    }
}