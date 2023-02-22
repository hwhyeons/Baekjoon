import java.io.*;
import java.util.*;

public class Main {

    //        int[] arr = {7, 6, 2, 5, 3, 1, 4};

//        int[] arr = {7, 6, 2};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int max = Integer.parseInt(br.readLine());

        int[] arr = new int[max];
        for (int i =0; i<max; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        merge(arr);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < max; i++) {
            sb.append(arr[i] + "\n");
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
//        for (int k : arr) {
//            System.out.println(k);
//        }

    }

    /**
     * 원리
     *
     */
    private static int[] merge(int[] arr) {
        if (arr.length == 1) {
            return arr;
        }
        int arLength = arr.length;
//        int[] first = new int[arLength/2];
//        int[] second = new int[arLength-(arLength/2)];
//        for (int i = 0; i < first.length; i++) {
//            first[i] = arr[i];
//        }
//        for (int i =0; i< second.length; i++) {
//            second[i] = arr[first.length+i];
//        }
        int[] first = merge(Arrays.copyOfRange(arr,0,arLength/2));
        int[] second = merge(Arrays.copyOfRange(arr,arLength/2,arLength));

        // d는 arr의 인덱스
        int i = 0, j = 0, d = 0;
        while (i < first.length && j < second.length) {
            if (first[i] > second[j]) {
                arr[d] = second[j];
                j++;
            } else {
                arr[d] = first[i];
                i++;
            }
            d++;
        }

        // 왼쪽 배열이 최대치에 도달한경우
        if (i == first.length) {
            for (int k = j; k < second.length; k++, d++) {
                arr[d] = second[k];
            }
        } else { // 오른쪽 배열이 먼저 최대치 >> 왼쪽배열에서 남은거 집어넣기
            for (int k = i; k < first.length; k++, d++) {
                arr[d] = first[k];
            }
        }
        return arr;
    }

}