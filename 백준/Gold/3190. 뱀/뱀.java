
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


class Coordinate {
    int x;
    int y;
    Coordinate(int x,int y) {
        this.x = x;
        this.y = y;
    }
}
class Snake {
    int xHead = 0; // 현재 머리 위치
    int yHead = 0;
    public LinkedList<Coordinate> all = new LinkedList<>(); // 가장 앞쪽이 헤드 / 뒤쪽이 테일
    Snake() {
        all.add(new Coordinate(0,0)); // 시작은 원점
    }

}


class DirChange {
    int time;
    boolean isRightDir;
}
public class Main{
    static int dx = 1; // 시작은 오른쪽
    static int dy = 0; // 시작은 오른쪽
    static int[][] arr;
    static Snake snake = new Snake();

    public static void main(String[] args) throws Exception {
//        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("test3.txt")));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int boardSize = Integer.parseInt(br.readLine());
        int appleCount = Integer.parseInt(br.readLine());
        arr = new int[boardSize][boardSize];
        arr[0][0] = 2; // 뱀의 시작점

        int currentTime = 1;
        // 0 : 사과도 없고 뱀도 없음
        // 1 : 사과가 있음
        // 2 : 뱀이 있음
        for (int i = 0; i < appleCount; i++) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            int row = Integer.parseInt(stk.nextToken())-1;
            int column = Integer.parseInt(stk.nextToken())-1;
            arr[row][column] = 1;
        }

        int dirChangeCount = Integer.parseInt(br.readLine());

        Queue<DirChange> queue = new LinkedList<>();
        for (int i = 0; i < dirChangeCount; i++) {
            DirChange d = new DirChange();
            StringTokenizer stk = new StringTokenizer(br.readLine());
            int time = Integer.parseInt(stk.nextToken());
            String dir = stk.nextToken();
            d.time = time;
            d.isRightDir = dir.equals("L") ? false : true;
            queue.add(d);
        }

        // 시작
        while (true) {
            boolean gameOver = move();
            if (gameOver) {
                break;
            }

            // 방향 전환 시점인 경우
            if (!queue.isEmpty() && queue.peek().time == currentTime) {
                boolean rightDir = queue.poll().isRightDir; // 맨 처음꺼 제거
                if (rightDir) {
                    if (dx == 1) {
                        dx = 0;
                        dy = 1;
                    } else if (dx == -1) {
                        dx = 0;
                        dy = -1;
                    } else if (dy == 1) {
                        dx = -1;
                        dy = 0;
                    } else if (dy == -1) {
                        dx = 1;
                        dy = 0;
                    }
                } else { // 왼쪽으로 전환
                    if (dx == 1) {
                        dx = 0;
                        dy = -1;
                    } else if (dx == -1) {
                        dx = 0;
                        dy = 1;
                    } else if (dy == 1) {
                        dx = 1;
                        dy = 0;
                    } else if (dy == -1) {
                        dx = -1;
                        dy = 0;
                    }
                }
            }
            currentTime++;
        }
        System.out.println(currentTime);
    }

    // 게임 끝나면 true
    private static boolean move() {
        snake.xHead+= dx;
        snake.yHead+= dy;
        // 벽과 충돌
        if (snake.xHead< 0 || snake.xHead== arr.length || snake.yHead < 0 || snake.yHead == arr.length) {
            return true;
        } else if (arr[snake.yHead][snake.xHead] == 2) { // 뱀과 충돌
            return true;
        }

        // 사과가 있는 경우 : 뱀꼬리는 그대로
        if (arr[snake.yHead][snake.xHead] == 1) {

        } else { // 사과가 없는 경우
            Coordinate xy = snake.all.removeLast(); // 꼬리 하나 줄이기
            arr[xy.y][xy.x] = 0; // 뱀 꼬리 하나 제거
        }
        arr[snake.yHead][snake.xHead] = 2; // 뱀 위치 지정
        snake.all.add(0,new Coordinate(snake.xHead,snake.yHead)); // 새 위치
        return false;
    }
}