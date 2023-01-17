import java.io.*;
import java.util.Deque;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int count = Integer.parseInt(br.readLine());
        Deque<Integer> q = new LinkedList();
        for (int i = 0; i < count; i++) {
            String[] tmp = br.readLine().split(" ");
            String a = tmp[0]; // 명령어
            switch (a) {
                case "push":
                    q.add(Integer.parseInt(tmp[1]));
                    break;
                case "front":
                    if (q.isEmpty()) bw.write("-1\n");
                    else bw.write(q.peekFirst().toString()+"\n");
                    break;
                case "pop":
                    if (q.isEmpty()) bw.write("-1\n");
                    else bw.write(q.pollFirst().toString()+"\n");
                    break;
                case "size":
                    bw.write(Integer.toString(q.size())+"\n");
                    break;
                case"back":
                    if (q.isEmpty()) bw.write("-1"+"\n");
                    else bw.write(q.peekLast().toString()+"\n");
                    break;
                case "empty":
                    bw.write(q.isEmpty() ? "1\n" : "0\n");
                    break;
                default:
                    break;
            }
        }
        bw.flush();
    }
}