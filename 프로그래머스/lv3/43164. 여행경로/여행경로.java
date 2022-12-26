import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;



class Ticket {
    String endPoint;
    boolean isUsed = false;
    Ticket(String endPoint) {
        this.endPoint = endPoint;
    }
}

class Solution {
    static ArrayList<String> answerList = new ArrayList<>();
    static HashMap<String,ArrayList<Ticket>> ticketMap;
    public String[] solution(String[][] tickets) {
        ticketMap = new HashMap<>();
        for (int i = 0; i < tickets.length; i++) {
            String startingPoint = tickets[i][0];
            String endPoint = tickets[i][1];
            if(ticketMap.containsKey(startingPoint)) { // 도시 중복
                ticketMap.get(startingPoint).add(new Ticket(endPoint));
            } else {
                ArrayList<Ticket> endPointArr = new ArrayList<>();
                endPointArr.add(new Ticket(endPoint));
                ticketMap.put(startingPoint,endPointArr);
            }
        }
        dfs("ICN","ICN",tickets.length);
        String minStr = Collections.min(answerList);
        String[] answers = new String[minStr.length()/3];
        for (int i = 0,j=0; i < minStr.length(); i+=3,j++) {
            answers[j] = minStr.substring(i,i+3);
        }
        return answers; // 3개씩 묶기
    }

    private static void dfs(String start, String all, int remainCount) {
        if (remainCount == 0) {
            answerList.add(all);
            return;
        }
        ArrayList<Ticket> tickets = ticketMap.get(start);
        if (tickets == null || tickets.size() ==0) { // 티켓은 남았지만 탈출이 불가능한 경우
            return;
        }
        for (int i = 0; i < tickets.size(); i++) {
            Ticket t = tickets.get(i);
            if (t.isUsed) continue;
            t.isUsed = true;
            dfs(t.endPoint,all+t.endPoint,remainCount-1);
            t.isUsed = false;
        }
    }
}