import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int allKg = Integer.parseInt(br.readLine());
        int answer = 0;
        int count5 = 0;
        int count3 = 0;
        int currentKG = 0;
        while (true) {
            currentKG = 3*count3 + 5*count5;
            if (currentKG == allKg) {
                answer = count3+count5;
                break;
            } else if (currentKG > allKg) {
                ++count3;
                --count5;
                continue;
            } else {
                if (count3 == 0) {
                    count5++;
                } else {
                    if (count5 == 0) {
                        answer = -1;
                        break;
                    }
                    count3++;
                }
            }
        }
        System.out.println(answer);
    }
}

