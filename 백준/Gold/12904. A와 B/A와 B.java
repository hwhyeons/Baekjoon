import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        final String S = br.readLine();
        final String T = br.readLine();

//        char[] strs = new char[T.length()];
        List<Character> strs = new ArrayList<>();
        for (int i=0; i<T.length();i++){
            strs.add(T.charAt(i));
        }

        int endLength = S.length();
        while (true) {
            if (endLength == strs.size()) break;
            char lastChar = strs.get(strs.size()-1);
            if (lastChar == 'A') {
                strs.remove(strs.size()-1);
            } else if (lastChar == 'B'){
                strs.remove(strs.size()-1);
                Collections.reverse(strs);
            } else {
                throw new Exception("Err");
            }
        }

        boolean tf = true;
        for (int i = 0; i < S.length(); i++) {
            if (strs.get(i) == S.charAt(i)) {
                continue;
            }
            tf=false;
            break;
        }
        if (tf) {
            System.out.println(1);
        } else {
            System.out.println(0);
        }

    }
}