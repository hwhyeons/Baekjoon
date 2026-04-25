import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        long k = Long.parseLong(br.readLine());
        final long endPoint = (long) Math.sqrt(k);
        long curDiv = 2L;
        List<Long> list = new ArrayList<>();
        while (curDiv <= endPoint) {
            if (k%curDiv == 0) {
                list.add(curDiv);
                k = k/curDiv;
                continue;
            }
            curDiv++;
        }
        // 남은 원소가 1이 아니라면 남은 값 그대로 추가
        if (k!=1) {
            list.add(k);
        }
        bw.write(Long.toString(list.size())+"\n");
        for (long l : list) {
            bw.write(Long.toString(l)+" ");
        }
        bw.flush();
    }
}