import java.util.Scanner;


public class Main{
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int minAB = Math.min(a, b);
        long left = 1L;
        int minDivide = 2;
        while (true) {
            int divide = -1;
            for (int i = minDivide; i <= minAB; i++) {
                if (a%i == 0 && b%i == 0) {
                    divide = i;
                    minDivide = Math.min(divide,minDivide);
                }
            }
            if (divide == -1) { // 답 X
                break;
            } else { // 답 O
                a /= divide;
                b /= divide;
                left *= divide;
                continue;
            }
        }
        System.out.println(left+"\n"+(a*b*left));
    }
}