import java.io.*;
import java.util.*;

public class Main{


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("test1.txt")));
        br.readLine();
        String g1S = br.readLine();
        StringBuffer sbf = new StringBuffer(g1S);
        g1S = sbf.reverse().toString();
        String g2S = br.readLine();

        final int time = Integer.parseInt(br.readLine());

        char[] g1 = g1S.toCharArray();
        char[] g2 = g2S.toCharArray();
        char[] all = new char[g1.length + g2.length];
        boolean[] dir = new boolean[all.length];
        for (int i = 0; i < g1.length; i++) {
            all[i] = g1[i];
            dir[i] = true;
        }
        for (int i = 0; i < g2.length; i++) {
            all[i+g1.length] = g2[i];
            dir[i+g1.length] = false;
        }

        int currentTime = 0;
        while (currentTime < time) {
            for (int i = 0; i < all.length-1; i++) {
                if (dir[i] && !dir[i+1]) {
                    swap(i,all,dir);
                    i++;
                }
            }
            currentTime++;
        }
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));
        bufferedWriter.write(all, 0, all.length);
        bufferedWriter.flush();

    }

    private static void swap(int i, char[] all, boolean[] dir) {
        char tmp = all[i];
        boolean tmpB = dir[i];
        all[i] = all[i+1];
        all[i+1] = tmp;
        dir[i] = dir[i+1];
        dir[i+1] = tmpB;
    }
}

