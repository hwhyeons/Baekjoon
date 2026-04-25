import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;

class Main {
    static int N;
    static int[][] arr;
    static HashMap<Integer,Integer> map = new HashMap<>();
    public static void main(String[] l) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N+1][2]; // time, reward
        String[] tmp;
        for (int i = 1; i <= N; i++) {
            tmp = br.readLine().split(" ");
            arr[i][0] = Integer.parseInt(tmp[0]);
            arr[i][1] = Integer.parseInt(tmp[1]);
        }
        System.out.println(go(1));
    }

    private static int go(int day) {
        Integer rt;
        if ((rt = map.get(day)) != null) return rt;
        if (day >= N+1) {// 아예 불가능 한 경우
            map.put(day,0);
            return 0;
        }
        int nextDay = day+arr[day][0];
        int doToday = arr[day][1];
        if (nextDay > N+1) { // 오늘 것을 수행 못하는 경우
            doToday = 0;
        }
        rt = Math.max(doToday+go(nextDay),go(day+1));
        map.put(day,rt);
        return rt;
    }
}