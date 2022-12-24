import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int answer = 0;
        int remain = Integer.parseInt(br.readLine().split(" ")[1]); // 남은 줄 수 있는 레벨
        TreeMap<Integer,Long> map = br.lines().map(Integer::parseInt).collect(Collectors.groupingBy(i->i,Collectors.counting()))
                        .entrySet().stream().collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue,(a, b)->a,TreeMap::new));
        Map.Entry<Integer,Long> minMap,nextMinMap;
        while (true) {
            minMap = map.pollFirstEntry();
            int multiplyConst = minMap.getValue().intValue(); // long 타입 -> int 타입
            int cur = minMap.getKey();
            if (map.isEmpty()) { // 원소가 하나뿐이라 한곳에 올인
                int plusCount = remain/multiplyConst;
                System.out.println(cur+plusCount);
                return;
            }
            nextMinMap = map.firstEntry();
            int next = nextMinMap.getKey();
            int gap = next-cur; // 그 다음으로 작은 원소와의 차이
            int bestPlusCount = gap;
            int plusCount = remain/multiplyConst; // 최대 줄 수 있는 개수
            if (plusCount >= bestPlusCount) {
                // 맵 원소 변경
                map.put(next,multiplyConst+nextMinMap.getValue());
                remain-=bestPlusCount*multiplyConst; // 남은 줄 수 있는 레벨
                continue;
            } else { // 못주는 경우
                System.out.println(cur+plusCount);
                return;
            }
        }
    }
}
