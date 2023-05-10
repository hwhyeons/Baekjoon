import java.util.Scanner;
import java.util.stream.Collectors;

interface Main{
    static void main(String[] a){
        System.out.println((new Scanner(System.in).useDelimiter("\n").tokens().skip(1).map(s-> {
            var b=s.split(" ");
            return Integer.toString(Integer.valueOf(b[0])+Integer.valueOf(b[1]));
        }).collect(Collectors.joining("\n"))));
    }
}