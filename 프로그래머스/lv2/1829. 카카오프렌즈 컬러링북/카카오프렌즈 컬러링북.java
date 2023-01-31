
import java.util.*;

class Solution {
    boolean[][] v;

    double rot = Math.PI/2;



    private int go(int[][] arr, int y, int x, int bfColor) {
        if (y < 0 || x <0 || y>=arr.length || x >= arr[0].length || v[y][x]) return 0;
        int color = arr[y][x];
        if (bfColor != color || color == 0) return 0;
        v[y][x] = true;
        int sum = 1; // 현재 영역 크기
        int lx = 1; // 우
        int ly = 0; // 우
        for (double deg = 0; deg<2*Math.PI; deg+=rot) {
            int newX = (int)(lx*Math.cos(deg) - ly*Math.sin(deg));
            int newY = (int)(lx*Math.sin(deg) + ly*Math.cos(deg));
            sum += go(arr,y+newY,x+newX,bfColor);
            lx = newX; ly = newY;
        }
        return sum;
    }


    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        v = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int color = picture[i][j];
                int tmp = go(picture,i,j,color);
                if (tmp > 0) {
                    numberOfArea++;
                }
                if (color !=0 ) maxSizeOfOneArea = Math.max(maxSizeOfOneArea,tmp);
            }
        }

        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
}