import java.util.*;
import java.util.stream.Collectors;

class Cake {
    int answer = 0;
    HashMap<Integer,Integer> map1 = new HashMap<>();
    HashMap<Integer,Integer> map2 = new HashMap<>();
    public void add(int num,boolean isMap1) {
        HashMap<Integer,Integer> map = isMap1 ? map1 : map2;
        int count = map.getOrDefault(num,0);
        map.put(num,count+1);
    }

    private void remove(int num) {
        int beforeCount = map1.get(num);
        if (beforeCount - 1 == 0) {
            map1.remove(num);
        } else {
            map1.put(num,beforeCount-1);
        }
        add(num,false);
    }

    public void removeAndCheck(int num) { // 옮기기
        remove(num);
        if (map1.size() == map2.size()){
            ++answer;
        }
    }
}

class Solution {
    public int solution(int[] topping) {
        Cake cake = new Cake();
        Arrays.stream(topping).forEach(t->cake.add(t,true));
        for (int i = 0; i < topping.length; i++) {
            cake.removeAndCheck(topping[i]);
        }
        return cake.answer;
    }
}