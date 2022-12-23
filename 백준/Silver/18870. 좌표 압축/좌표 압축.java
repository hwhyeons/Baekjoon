import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    static int sum = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int COUNT = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        Integer[] arr = Arrays.stream(br.readLine().split(" ")).map(Integer::parseInt).toArray(Integer[]::new);
        HashMap<Integer,Integer> map = (HashMap<Integer,Integer>)Arrays.stream(arr).distinct().sorted().collect(Collectors.toMap(Integer::intValue,(val)->sum++));
        Arrays.stream(arr).forEach(i-> sb.append(map.get(i)).append(" "));
        System.out.println(sb.substring(0,sb.length()-1));
    }
}
