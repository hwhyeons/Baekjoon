
import java.util.*;
import java.util.stream.Collectors;

class Solution {

    // arr : operator
    private long cal(ArrayList<String> arr,ArrayList<Object> list) {
        for (String op : arr) {
            int idx;
            while ((idx = list.indexOf(op)) != -1) {
                long a = (long)list.get(idx-1);
                long b = (long)list.get(idx+1);
                if (op.equals("*")) {
                    list.set(idx,a*b);
                } else if (op.equals("+")) {
                    list.set(idx,a+b);
                } else {
                    list.set(idx,a-b);
                }
                list.remove(idx+1);
                list.remove(idx-1);
            }
        }
        return Math.abs((long)list.get(0));
    }
    public long solution(String expression) {
        ArrayList<Object> list = new ArrayList<>();
        int s = 0;
        HashSet<String> operators = new HashSet<>();
        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            if (c == '-' || c == '*' || c== '+') {
                String oper = expression.substring(i,i+1);
                list.add(Long.parseLong(expression.substring(s, i)));
                list.add(oper);
                operators.add(oper);
                s = i+1;
            }
        }
        if (s < expression.length()) {
            list.add(Long.parseLong(expression.substring(s,expression.length())));
        }
        int idx = 0; // 인덱스
        long ans = Long.MAX_VALUE;

        ArrayList<ArrayList<String>> prior = new ArrayList<>();
        if (operators.isEmpty()) {
            return (long)list.get(0);
        } else if (operators.size() ==1) {
            prior.add(new ArrayList<>(Arrays.asList(operators.iterator().next())));
        } else if (operators.size() == 2) {
            ArrayList<String> tmp = (ArrayList<String>)operators.stream().collect(Collectors.toList());
            ArrayList<String> tmp2 = (ArrayList<String>)tmp.clone();
            Collections.reverse(tmp2);
            prior.add(tmp);
            prior.add(tmp2);
        } else {
            ArrayList<String> tmp = (ArrayList<String>)operators.stream().collect(Collectors.toList());
            prior.add(new ArrayList<>(Arrays.asList(tmp.get(0),tmp.get(1),tmp.get(2))));
            prior.add(new ArrayList<>(Arrays.asList(tmp.get(0),tmp.get(2),tmp.get(1))));
            prior.add(new ArrayList<>(Arrays.asList(tmp.get(1),tmp.get(0),tmp.get(2))));
            prior.add(new ArrayList<>(Arrays.asList(tmp.get(1),tmp.get(2),tmp.get(0))));
            prior.add(new ArrayList<>(Arrays.asList(tmp.get(2),tmp.get(0),tmp.get(1))));
            prior.add(new ArrayList<>(Arrays.asList(tmp.get(2),tmp.get(1),tmp.get(0))));
        }

        var it = prior.iterator();
        long max = -1;
        while (it.hasNext()) {
            max = Math.max(max,cal(it.next(),(ArrayList<Object>)list.clone())) ;
        }
        return max;
    }
}
