
import java.util.*;


class Solution {
    boolean[][] v;

    int[] dx= {0,0,-1,1};
    int[] dy= {-1,1,0,0};

    private int go(int[][] arr, int y, int x) {
        int color = arr[y][x];
        v[y][x] = true;
        if (color == 0) return 0;
        int sum = 1; // 현재 영역 크기
        int nx,ny;
        for (int i = 0; i < 4; i++) {
            nx = x+dx[i];
            ny = y+dy[i];
            if (nx < 0 || ny <0 || ny>=arr.length || nx >= arr[0].length) continue;
            if (v[ny][nx]) continue;
            if (arr[ny][nx] == color) {
                sum += go(arr,ny,nx);
            }
        }
        return sum;
    }


    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        v = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j]) continue;
                int tmp = go(picture,i,j);
                if (tmp > 0) numberOfArea++;
                maxSizeOfOneArea = Math.max(maxSizeOfOneArea,tmp);
            }
        }

        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
}