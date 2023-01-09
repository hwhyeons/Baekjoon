
class Point {
    int leftSum = 0; // 왼쪽으로 들어온 경우 (0,0)을 위해 기본은 1
    int downSum = 0; // 아래 방향으로 들어온 경우
    int type; // 0 또는 1또는 2
}

class Solution {
    static int width, height;
    static int MOD = 20170805;

    public int solution(int m, int n, int[][] cityMap) {
        width = n;
        height = m;
        Point[][] arr = new Point[height][width];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                Point p = new Point();
                p.type = cityMap[i][j];
                arr[i][j] = p;
            }
        }
        arr[0][1].leftSum = 1;
        arr[0][1].downSum = 0;
        arr[1][0].leftSum = 0;
        arr[1][0].downSum = 1;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if ((y == 0 && x == 0) || (y==0 && x==1) || (y==1 && x==0)) continue;
                Point p = arr[y][x];
                if (p.type == 1) { // 아예 못오는 경우
                    p.leftSum = 0;
                    p.downSum = 0;
                    continue;
                }

                int left=0,up=0;
                // 왼쪽에서 오는 경우
                if (x-1 >= 0) {
                    Point leftPoint = arr[y][x-1];
                    if (leftPoint.type == 2) left = leftPoint.leftSum;
                    else left = leftPoint.leftSum+leftPoint.downSum;
                }
                // 위에서 오는 경우
                if (y-1>=0) {
                    Point upPoint = arr[y-1][x];
                    if (upPoint.type == 2) up = upPoint.downSum;
                    else up = upPoint.leftSum+upPoint.downSum;
                }

                if (left >= MOD) left = left%MOD;
                if (up >= MOD) up = up%MOD;
                p.leftSum = left;
                p.downSum = up;
            }
        }
        int answer = (arr[height-1][width-1].downSum+arr[height-1][width-1].leftSum)%MOD;
        return answer;
    }
}