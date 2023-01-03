import java.io.*;
import java.util.StringTokenizer;

class Wall { // 각 위치에 대한 벽 정보
    boolean left,right,up,down,isVisited;
}


public class Main {
    static Wall[][] wallArray;
    static int height;
    static int width;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());
        width = Integer.parseInt(stk.nextToken());
        height = Integer.parseInt(stk.nextToken());
        wallArray = new Wall[height][width];

        for (int i = 0; i < height; i++) { // i = y좌표
            stk = new StringTokenizer(br.readLine());
            int j = 0; // j는 x좌표
            while (stk.hasMoreTokens()) {
                int n = Integer.parseInt(stk.nextToken());
                Wall w = new Wall();
                int bit = 1;
                if ((n&bit) != 0) w.left = true;
                if ((n&(bit<<1)) != 0) w.up = true;
                if ((n&(bit<<2)) != 0) w.right = true;
                if ((n&(bit<<3)) != 0) w.down = true;
//                if (hex.length() == 4) w.down = true; // 납
//                if (hex.length() >= 3 && hex.charAt(hex.length() - 3) == '1') w.right = true; // 동
//                if (hex.length() >= 2 && hex.charAt(hex.length() - 2) == '1') w.up = true;
//                if (hex.length() >= 1 && hex.charAt(hex.length() - 1) == '1') w.left = true;
                wallArray[i][j] = w;
                ++j;
            }
        }

        // 1. 이 성의 방 개수
        int roomCount = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                roomCount = getRoom(i,j) >= 1 ? roomCount + 1 : roomCount;
            }
        }
        System.out.println(roomCount);
        clearVisited(); // 방문 초기화 (기존 배열 재활용)

        // 2. 가장 넓은 방의 넓이
        int maxRoomArea = Integer.MIN_VALUE;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                maxRoomArea = Math.max(getRoom(i,j),maxRoomArea);
            }
        }
        System.out.println(maxRoomArea);
        clearVisited(); // 방문 초기화 (기존 배열 재활용)

        int maxWithRemove = Integer.MIN_VALUE;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                Wall w = wallArray[i][j];
                if (w.left) {
                    w.left = false;
                    for (int i1 = 0; i1 < height; i1++) {
                        for (int j1 = 0; j1 < width; j1++) {
                            maxWithRemove = Math.max(getRoom(i,j),maxWithRemove);
                        }
                    }
                    w.left = true;
                }
                clearVisited(); // 방문 초기화 (기존 배열 재활용)
                if (w.right) {
                    w.right = false;
                    for (int i1 = 0; i1 < height; i1++) {
                        for (int j1 = 0; j1 < width; j1++) {
                            maxWithRemove = Math.max(getRoom(i,j),maxWithRemove);
                        }
                    }
                    w.right = true;
                }
                clearVisited(); // 방문 초기화 (기존 배열 재활용)
                if (w.down) {
                    w.down = false;
                    for (int i1 = 0; i1 < height; i1++) {
                        for (int j1 = 0; j1 < width; j1++) {
                            maxWithRemove = Math.max(getRoom(i,j),maxWithRemove);
                        }
                    }
                    w.down = true;
                }
                clearVisited(); // 방문 초기화 (기존 배열 재활용)
                if (w.up) {
                    w.up = false;
                    for (int i1 = 0; i1 < height; i1++) {
                        for (int j1 = 0; j1 < width; j1++) {
                            maxWithRemove = Math.max(getRoom(i,j),maxWithRemove);
                        }
                    }
                    w.up = true;
                }
                clearVisited(); // 방문 초기화 (기존 배열 재활용)
            }
        }
        System.out.println(maxWithRemove);
    }

    private static void clearVisited() { // 방문 초기화
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                wallArray[i][j].isVisited = false;
            }
        }
    }

    private static int getRoom(int y, int x) {
        if (y<0 || y>=height || x<0 || x>=width) return 0;
        Wall w = wallArray[y][x];
        if(w.isVisited) return 0;
        w.isVisited = true;
        int count =1; // 자기 자신
        // 벽이 없으면 진행
        if (!w.left) count+=getRoom(y,x-1);
        if (!w.right) count+=getRoom(y,x+1);
        if (!w.up) count+=getRoom(y-1,x);
        if (!w.down) count+=getRoom(y+1,x);
        return count;
    }
}

