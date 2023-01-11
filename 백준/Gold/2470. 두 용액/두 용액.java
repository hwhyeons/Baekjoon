import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main{
    public static void main(String[] args) throws Exception {
        int a = -1;
        int b = -1;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).sorted().toArray();
        int min = Integer.MAX_VALUE;
        loop:
        for (int i = 0; i < arr.length; i++) {
            int start =0;
            int end = arr.length-1;
            int cur = arr[i];
            int rcur = -cur;
            int mid = -1;
            while(start<=end) {
                mid = (start+end)/2;
                if (arr[mid] == rcur) {// 바로 정답
                    a = cur;
                    b= rcur;
                    break loop;
                } else if (arr[mid] > rcur) {
                    end = mid -1;
                } else {
                    start = mid+1;
                }
            }
            if (mid != i && min > Math.abs(cur+arr[mid])) {
                a = cur;
                b = arr[mid];
                min = Math.abs(cur+arr[mid]);
            }
            if (mid + 1 < arr.length && mid + 1 != i) {
                if (min > Math.abs(cur+arr[mid+1])) {
                    a = cur;
                    b = arr[mid+1];
                    min = Math.abs(cur+arr[mid+1]);
                }
            }
            if (mid - 1>= 0 && mid-1 != i) {
                if (min > Math.abs(cur+arr[mid-1])) {
                    a = cur;
                    b = arr[mid-1];
                    min = Math.abs(cur+arr[mid-1]);
                }
            }
            if (i -1 >= 0) {
                if (min > Math.abs(arr[i-1]+cur)) {
                    a = cur;
                    b = arr[i-1];
                    min = Math.abs(cur+arr[i-1]);
                }
            }
        }
        System.out.println(a+" "+b);
    }
}