import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int COUNT = Integer.parseInt(br.readLine());
        HashMap<Character,Long> map = new HashMap<>();
        for (int i = COUNT-1; i >= 0; i--) {
            char[] charArr = br.readLine().toCharArray();
            for (int j = charArr.length-1,idx=0; j >= 0; j--,idx++) {
                char c = charArr[j];
                if (map.containsKey(c)) {
                    long before = map.get(c);
                    map.put(c,(long)(before+Math.pow(10,idx)));
                } else {
                    map.put(c,(long)Math.pow(10,idx));
                }
            }
        }
        ArrayList<Map.Entry<Character,Long>> sorted = (ArrayList<Map.Entry<Character,Long>>)map.entrySet().stream().sorted(Comparator.comparing(Map.Entry::getValue,Collections.reverseOrder())).collect(Collectors.toList());
        int startNumber = 9;
        long sum = 0;
        for (int i = 0; i < sorted.size(); i++) {
            Map.Entry<Character,Long> ent = sorted.get(i);
            sum += startNumber*ent.getValue();
            startNumber--;
        }
        System.out.println(sum);
    }
}