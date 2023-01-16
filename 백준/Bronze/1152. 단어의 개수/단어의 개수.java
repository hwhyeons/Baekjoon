
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

/*
//        베열 + split 테스트
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] arr = br.readLine().split(" ");
        int minus = 0;
        if (arr.length !=0) {
            if (arr[0].equals("")) minus++;
            if (arr.length >=2&& arr[1].equals("")) minus++;
        }
        System.out.println(arr.length-minus);
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.println(sc.tokens().count());
    }
}