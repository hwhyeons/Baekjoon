import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main{
    static int answer = 0;
    static int[] dir_x = {0,0,-1,1}; // 상하 좌우 순서
    static int[] dir_y = {1,-1,0,0}; // 상하 좌우 순서
    public static void main(String[] args) throws Exception{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int TEST_CASE = Integer.parseInt(br.readLine());
        for (int i = 0; i < TEST_CASE; i++) {
            int[] tmp = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int width = tmp[0];
            int height = tmp[1];
            int count = tmp[2];
            int[][] arr = new int[height][width];
            for (int j = 0; j < count; j++) {
                StringTokenizer st = new StringTokenizer(br.readLine()," ");
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                arr[y][x] = 1;
            }

            // 해충
            int x1,y1;
            for (int y = 0; y < height; y++) {
                for (int x = 0; x < width; x++) {
                    if (arr[y][x] == 1){
                        answer++;
                        make2(y,x,width,height,arr);
                    } else {
                        continue;
                    }
                }
            }
            System.out.println(answer);
            answer = 0;
        }
    }
    private static void make2(int y, int x, int width, int height, int[][] arr) {
        if (x < 0 || x >= width || y < 0 || y >= height) return;
        if (arr[y][x] !=1) return;
        arr[y][x] = 2;
        // 상하 좌우 방향 체크
        int y1,x1;
        for (int dirIndex = 0; dirIndex < 4; dirIndex++) {
            x1 = x + dir_x[dirIndex];
            y1 = y + dir_y[dirIndex];
            make2(y1,x1,width,height,arr);
        }
    }
}

