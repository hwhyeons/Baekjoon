import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;


public class Main{

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static void dfs(String[] arr,String[] out, int depth, int index, int n, int r, int aeiou, int j) throws Exception{
        if (depth == r){
            if (aeiou == 0 || j < 2) {
                return;
            }
            for (String t : out) {
                bw.write(t);
            }
            bw.write("\n");
            return;
        }
        for (int i = index; i < n; i++) {
            out[depth] = arr[i];
            if (arr[i].equals( "a" )|| arr[i].equals( "e" )|| arr[i].equals( "i" )|| arr[i].equals( "o" )||arr[i].equals( "u" )) {
                dfs(arr,out,depth+1,i+1,n,r,aeiou+1,j);
            } else {
                dfs(arr,out,depth+1,i+1,n,r,aeiou,j+1);
            }
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        int L = Integer.parseInt(tmp[0]);
        int C = Integer.parseInt(tmp[1]);
        String[] arr = Arrays.stream(br.readLine().split(" ")).sorted().toArray(String[]::new);
        String[] out = new String[L];
        dfs(arr,out,0,0,C,L,0,0);
        bw.flush();
    }
}