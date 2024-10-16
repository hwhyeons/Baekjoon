import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        System.out.println((new BufferedReader(new InputStreamReader(System.in)).lines().skip(1).mapToInt(Integer::parseInt).sorted().mapToObj(Integer::toString).collect(Collectors.joining("\n"))));
    }
}
