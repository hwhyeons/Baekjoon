import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        HashSet<Integer> set = new HashSet<>();
        int[] nums = {1,5,10,50};
        set.add(1);
        set.add(5);
        set.add(10);
        set.add(50);
        for (int i =2;i<=N;i++) {
            // 원소 추가하면서 방문하면 무한 참조 가능하기 때문에 임시 set만들기
            HashSet<Integer> tmpSet = new HashSet<>();
            for (int num : set) {
                for (int add : nums) {
                    int nextNum = num + add;
                    if (tmpSet.contains(nextNum)) continue;
                    tmpSet.add(nextNum);
                }
            }
            set = tmpSet;
        }

        bw.write(set.size()+"");
        bw.flush();
    }
}