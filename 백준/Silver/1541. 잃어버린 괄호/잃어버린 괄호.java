import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        System.out.println(Arrays.stream(new BufferedReader(new InputStreamReader(System.in)).readLine().split("\\-"))
                .mapToInt(arr-> Arrays.stream(arr.split("\\+")).mapToInt(Integer::parseInt).sum())
                .reduce(Integer.MAX_VALUE,(sum, n)->sum == Integer.MAX_VALUE ? n : sum-n));
    }
}