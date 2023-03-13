import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.regex.Pattern;


public class Main {
//    static String regex = "((100+1+) | (01))+";
    static String regex = "(100+1+|01)+";
    public static void main(String args[]) throws Exception {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int tCount = Integer.parseInt(br.readLine());
        for (int i = 0; i < tCount; i++) {
            String cur = br.readLine();
            bw.write(Pattern.matches(regex,cur) ? "YES" : "NO");
            bw.write("\n");
        }
        bw.flush();
    }
}

