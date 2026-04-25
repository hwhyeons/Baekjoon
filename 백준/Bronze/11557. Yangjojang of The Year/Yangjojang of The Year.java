import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCaseCount = Integer.parseInt(br.readLine());
        String[] tokens = null;
        String name = null;
        String maxName = null;
        int maxAmount = -1;
        int amount = -1;
        for (int i = 0; i < testCaseCount; i++) {
            int collegeCount = Integer.parseInt(br.readLine());
            for (int j = 0; j < collegeCount; j++) {
                tokens = br.readLine().split(" ");
                name = tokens[0];
                amount = Integer.parseInt(tokens[1]);
                if (amount > maxAmount) {
                    maxName = name;
                    maxAmount = amount;
                }
            }
            System.out.println(maxName);
        }
    }
}