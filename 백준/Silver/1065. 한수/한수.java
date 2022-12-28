import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;

public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        int sum =0;
        for (int i = 1; i <= num; i++) {
            sum+=f(i);
        }
        System.out.println(sum);
    }

    private static int f(int i) {
        String n = Integer.toString(i);
        int count = i < 100 ? 1 : 0;
        int before = Integer.MAX_VALUE;
        boolean c = false;
        for (int j = 0; j < n.length()-1; j++) {
            int before1 = n.charAt(j + 1) - n.charAt(j);
            if (before1 == before)
                count++;
            else if (c == false)
                before = before1;
                c = true;
        }
        return count;
    }
}