
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(stk.nextToken());
        int K = Integer.parseInt(stk.nextToken());
//        LinkedList<Integer> list = br.readLine().chars().boxed().collect(Collectors.toCollection(LinkedList::new));
        int[] arr = br.readLine().chars().map(i->i-48).toArray();
        int i = 0;
        int min = arr[0];
//        int removeStartPoint = 0;
        int remain = K;
        while (i < arr.length && remain > 0) {
            int c = arr[i];
            if (c > min) { // max 갱신 >> 이전꺼 전부 삭제
                for (int j = i-1; j>=0; j--) {
                    if (arr[j] >= arr[i]) break;
                    if (arr[j] == -1) continue;
                    arr[j] = -1;
                    remain--;
                    if (remain == 0) break;
                }
                min = arr[i];
//                removeStartPoint = i;
            } else {
                    min = Math.min(min,arr[i]);
            }
            ++i;
        }
        if (remain > 0) { // 남은게 있으면 뒤에서 부터 지우기
            for (int j = arr.length-1; j >= 0; j--) {
                if (arr[j] == -1) continue;
                arr[j] = -1;
                remain--;
                if (remain == 0) break;;
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int val : arr) {
            if (val != -1) {
                sb.append(Integer.toString(val));
            }
        }
        System.out.println(sb);
    }
}