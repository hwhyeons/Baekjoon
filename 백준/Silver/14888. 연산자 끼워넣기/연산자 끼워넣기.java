import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static int N;
    static int[] numArr;
    public static void main(String[] l) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        numArr = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            numArr[i] = Integer.parseInt(st.nextToken());
        }
//        numArr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] operationArr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        System.out.println(cal(0,numArr[0], operationArr,false));
        System.out.println(cal(0,numArr[0], operationArr,true));
    }

    private static int cal(int operationIdx, int before, int[] operations,boolean isMin) { // operations : 남은 연산자 배열
        if (operationIdx > N-2) return before;
        int maxOrMin = isMin ? Integer.MAX_VALUE : Integer.MIN_VALUE;
        int[] answer = {maxOrMin, maxOrMin, maxOrMin, maxOrMin};
        if (operations[0] > 0) { // 덧셈
            int[] opt = operations.clone();
            opt[0] = opt[0]-1;
            answer[0] = cal(operationIdx+1,before+numArr[operationIdx+1],opt,isMin);
        }
        if (operations[1] > 0) { // 뺄셈
            int[] opt = operations.clone();
            opt[1] = opt[1]-1;
            answer[1] = cal(operationIdx+1,before-numArr[operationIdx+1],opt,isMin);
        }
        if (operations[2] > 0) { // 곱셈
            int[] opt = operations.clone();
            opt[2] = opt[2]-1;
            answer[2] = cal(operationIdx+1,before*numArr[operationIdx+1],opt,isMin);
        }
        if (operations[3] > 0) { // 나눗셈
            int[] opt = operations.clone();
            opt[3] = opt[3]-1;
            answer[3] = cal(operationIdx+1,before/(numArr[operationIdx+1]),opt,isMin);
        }
        return isMin ? Math.min(Math.min(answer[0],answer[1]),Math.min(answer[2],answer[3])) : Math.max(Math.max(answer[0],answer[1]),Math.max(answer[2],answer[3]));
    }
}