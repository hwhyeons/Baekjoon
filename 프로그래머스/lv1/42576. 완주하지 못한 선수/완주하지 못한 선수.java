import java.util.Arrays;
import java.util.HashMap;
import java.util.stream.Collectors;

class Solution {
    public String solution(String[] participant, String[] completion) {
        HashMap<String,Long> map = (HashMap<String,Long>)Arrays.stream(participant).collect(Collectors.groupingBy(s->s,Collectors.counting()));
        for (String s : completion) {
            if (!map.containsKey(s)) return s;
            if(map.get(s) == 1) {
                map.remove(s);
            } else {
                map.put(s,map.get(s)-1);
            }
        }
        return map.keySet().iterator().next();
    }
}