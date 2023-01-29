import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;


class Pair {
    int index;
    int height;
}
public class Main{

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int N = Integer.parseInt(br.readLine());
        int[] answer = new int[N];
        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingInt(p->p.height));
        for (int i = arr.length - 1; i >= 0; i--) {
            int height = arr[i];

            // 우선순위 큐에서 제거
            while (pq.size()>0 && pq.peek().height <= height) {
                Pair pair = pq.poll();
                answer[pair.index] = i+1; // 실제 위치는 인덱스 +1
            }

            // 새로운 원소 추가
            Pair pair = new Pair();
            pair.index = i;
            pair.height = height;
            pq.add(pair);
        }

        while (!pq.isEmpty()) { // 남아 있는 원소가 있다면 모두 0으로 처리
            Pair pair = pq.poll();
            answer[pair.index] = 0;
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int a : answer) {
            bw.write(a+" ");
        }
        bw.flush();
    }
}