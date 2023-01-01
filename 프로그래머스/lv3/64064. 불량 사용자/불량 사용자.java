import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.regex.Pattern;
import java.util.stream.Collectors;
class Information{
    boolean isUsed = false;
    int id; // 고유 id
}
class Solution {
    static ArrayList<HashSet<String>> answerSet;
    static int len;
    static int id_only;
    static Object[] arr;
    static HashMap<String,Information> usedMap;
    public int solution(String[] user_id, String[] banned_id) {
        usedMap = new HashMap<>();
        answerSet = new ArrayList<>();
        id_only = 0;
        len = 0;
        String[] banned_id_regex = Arrays.stream(banned_id)
                .map(s -> s.replaceAll("\\*", "\\\\w")).toArray(String[]::new);
        arr = Arrays.stream(banned_id_regex).map(regex-> {
            ArrayList<String> arr = new ArrayList<>();
            for (int i = 0; i < user_id.length; i++) {
                if (Pattern.matches(regex,user_id[i])) {
                    String name = user_id[i];
                    arr.add(name);
                    Information information = new Information();
                    information.id = id_only++;
                    usedMap.put(name,information);
                }
            }
            return arr;
        }).toArray();
        len = arr.length;
        dfs(0,"");
        return answerSet.size();
    }
    private static void dfs(int idx,String nameAccumulated) {
        if (idx >= len) {
            nameAccumulated = nameAccumulated.substring(1);
            HashSet<String> set = (HashSet<String>)Arrays.stream(nameAccumulated.split(" ")).collect(Collectors.toSet());
            for (int i = 0; i < answerSet.size(); i++) {
                if (answerSet.get(i).containsAll(set) && set.containsAll(answerSet.get(i))) return; 
            }
            answerSet.add(set);
            return;
        }
        ArrayList<String> bannedList = (ArrayList<String>)arr[idx];
        for (int i = 0; i < bannedList.size(); i++) {
            String name = bannedList.get(i);
            Information information = usedMap.get(name);
            if (information.isUsed) continue;
            information.isUsed = true;
            dfs(idx+1,nameAccumulated+" "+name);
            information.isUsed = false;
        }
    }
}

