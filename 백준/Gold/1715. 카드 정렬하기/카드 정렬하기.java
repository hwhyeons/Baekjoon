import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int N = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> queue = br.lines().map(Integer::parseInt).collect(Collectors.toCollection(PriorityQueue::new));
        int sum = 0;
        while (!queue.isEmpty()) {
            int n1 = queue.poll();
            if (queue.isEmpty()) {
                break;
            }
            int n2 = queue.poll();
            sum += n1 + n2;
            queue.add(n1 + n2);
        }
        System.out.println(sum);
    }
}
