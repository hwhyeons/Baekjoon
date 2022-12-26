import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public double[] solution(int k, int[][] ranges) {
        ArrayList<Integer> coordinate = new ArrayList<>(); // 인덱스 : x좌표 / 값 : y좌표
        coordinate.add(k); // 시작 좌표 추가
        while (k != 1) {
            k = k%2 == 0 ? k/2 : k*3+1;
            coordinate.add(k);
        }
        final int lastX = coordinate.size()-1;
        double[] answer = new double[ranges.length];
        for (int i = 0; i < ranges.length; i++) {
            int startX = ranges[i][0];
            int endX = lastX+ranges[i][1];
            if (endX < startX) {
                answer[i] = -1.0;
                continue;
            }
            answer[i] = getArea(coordinate,startX,endX);
        }
        return answer;
    }

    private double getArea(ArrayList<Integer> coordinate, int startX, int endX) {
        int y1,y2;
        double sum = 0.0;
        for (int i = startX; i <= endX-1; i++) {
            y1 = coordinate.get(i);
            y2 = coordinate.get(i+1);
            sum += (Math.max(y1, y2))-(0.5*Math.abs(y1-y2)*1);
        }
        return sum;
    }
}
