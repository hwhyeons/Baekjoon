
import java.util.*;


class Work {
    int startTime;
    int doTime;
}
class Solution {

    HashMap<Integer,ArrayList<Work>> timeMap = new HashMap<>();
    public int solution(int[][] jobs) {
        int size = jobs.length;
        for (int i = 0; i < jobs.length; i++) {
            Work w = new Work();
            w.startTime = jobs[i][0];
            w.doTime = jobs[i][1];
            if (timeMap.containsKey(w.startTime)) {
                timeMap.get(w.startTime).add(w);
            } else {
                ArrayList<Work> tmp = new ArrayList<>();
                tmp.add(w);
                timeMap.put(w.startTime,tmp);
            }
        }
        PriorityQueue<Work> pq = new PriorityQueue<>(Comparator.comparingInt(w -> w.doTime));
        int curTime = 0;
        int answer = 0;
        int nextFinishTime = 0;
        while(true) {
            // 현재 시간에 맞는 데이터 넣기
            if (timeMap.containsKey(curTime)) {
                ArrayList<Work> works = timeMap.remove(curTime);
                if (works!=null) pq.addAll(works);
            }
            if (curTime >= nextFinishTime) { // 끝날시간 된 경우 : 새로운 일 시작
                Work nextWork = pq.poll();
                if (nextWork == null){
                    if (timeMap.isEmpty()) {
                        break; // 현재 진행중인 일도 없으면서 더이상 할게 없는 경우
                    }
                } else {
                    nextFinishTime = curTime+nextWork.doTime;
                    answer += nextFinishTime-nextWork.startTime;
                }
            }
            curTime++;
        }
        return (int)((double)answer/size);
    }
}
