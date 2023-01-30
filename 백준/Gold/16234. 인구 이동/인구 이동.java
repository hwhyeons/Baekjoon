import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


class Pair {
    int x;
    int y;
}
public class Main{

    static int[] dx = {0,0,-1,1};
    static int[] dy = {-1,1,0,0};
    private static void go(int row, int col, ArrayList<Pair> p) {
        if (v[row][col]) return;
        v[row][col] = true;
        int val = arr[row][col];
        for (int i = 0; i < 4; i++) {
            int x = col+dx[i];
            int y = row+dy[i];
            if (!(y >= 0 && y < arr.length && x >= 0 &&x < arr.length)) continue;
            if (v[y][x]) continue;
            int gap = Math.abs(val-arr[y][x]);
            if (!(gap >= L && gap <= R)) continue;
            Pair curP = new Pair();
            curP.x = x;
            curP.y = y;
            p.add(curP);
            go(y,x,p);
        }
        return;
    }

    static int L,R;
    static int arr[][];
    static boolean v[][];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());
        final int N = Integer.parseInt(stk.nextToken());
        L = Integer.parseInt(stk.nextToken());
        R = Integer.parseInt(stk.nextToken());
        arr = new int[N][N];
        for (int i = 0; i < N; i++) {
            arr[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }

        v = new boolean[N][N];
        boolean ok = false;
        int time = 0;
        while (true) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (v[i][j]) continue;
                    ArrayList<Pair> a = new ArrayList<>();
                    Pair p = new Pair();
                    p.x = j;
                    p.y = i;
                    a.add(p);
                    go(i,j,a);
                    // 해당 그룹에 있는 값들 전부 평균으로 변경
                    if (a.size() >= 2) { // 그룹으로 묶인 경우
                        ok = true;
                        int avg = (int)a.stream().mapToInt(pair->arr[pair.y][pair.x]).average().getAsDouble();
                        a.stream().forEach(pair->arr[pair.y][pair.x] = avg);
                    }
                }
            }
            if (ok) {
                time++; // 시간 증가
                v = new boolean[N][N];
                ok = false;
            } else break;
        }
        System.out.println(time);
    }
}