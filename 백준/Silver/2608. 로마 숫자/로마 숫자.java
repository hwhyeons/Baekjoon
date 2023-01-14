import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

class R {
    String str;
    int remainCount;
    int num;
    HashSet<R> crashList = new HashSet<>();

    R(String str, int remainCount, int num) {
        this.str = str;
        this.remainCount = remainCount;
        this.num = num;
    }

    public int use(){
        --remainCount;
        return num;
    }
}
public class Main{
    static R I = new R("I",Integer.MAX_VALUE,1);
    static R IV = new R("IV",1,4);
    static R V = new R("V",1,5);
    static R IX = new R("IX",1,9);
    static R X = new R("X",Integer.MAX_VALUE,10);
    static R XL = new R("XL",1,40);
    static R L = new R("L",1,50);
    static R XC = new R("XC",1,90);
    static R C = new R("C",Integer.MAX_VALUE,100);
    static R CD = new R("CD",1,400);
    static R D = new R("D",1,500);
    static R CM = new R("CM",1,900);
    static R M = new R("M",Integer.MAX_VALUE,1000);


    static R[] numArr = {M,CM,D,CD,C,XC,L,XL,X,IX,V,IV,I};
    static int currentMaxNumberIndex = 0; // 0번 = 1000원

    private static boolean isCrash(R r1, R r2) {
        if (r1.crashList.contains(r2) || r2.crashList.contains(r1)) return true;
        return false;
    }

    private static String convertString(int num) {
        ArrayList<R> list = new ArrayList<>();
        int remainSum = num; // 남은 금액
        while (remainSum > 0) {
            R maxR =  numArr[currentMaxNumberIndex];
            int idx = currentMaxNumberIndex;
            int max = maxR.num; // 한번에 최대한 할 수 있는 수
            if (remainSum >= max) { // 예를들어 2490원 남았는데 1000원짜리 쓸 수 있는 경우
                while (true) {
                    if (list.isEmpty()) break;
                    if (isCrash(maxR,list.get(list.size()-1)) || maxR.remainCount == 0 || (list.size()>=3 && list.get(list.size()-1) == maxR && list.get(list.size()-2) == maxR&& list.get(list.size()-3) == maxR)) { // 쓸 수는 있지만 충돌 또는 연속 3번 또는 개수 부족
                        maxR = numArr[++idx];
                        continue;
                    } else {
                        break;
                    }
                }
                remainSum -= maxR.use();
                list.add(maxR);
            } else {
                ++currentMaxNumberIndex;
                continue;
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < list.size(); i++) {
            sb.append(list.get(i).str);
        }
        return sb.toString();
    }

    private static int getNum(String s){
        int before = Integer.MAX_VALUE;
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            String cur = s.substring(i,i+1);
            int n = map.get(cur).num;
            if (n > before) {
                String bfStr = s.substring(i-1,i);
                String word = bfStr+cur;
                sum -= map.get(bfStr).num; // 이전꺼 더해진거 지워준다
                sum += map.get(word).num;
            } else {
                sum += n;
            }
            before = n;
        }
        return sum;
    }

    static HashMap<String,R> map = new HashMap<>();
    public static void main(String[] args) throws Exception{
        map.put("I",I);
        map.put("V",V);
        map.put("X",X);
        map.put("L",L);
        map.put("C",C);
        map.put("D",D);
        map.put("M",M);
        map.put("IV",IV);
        map.put("IX",IX);
        map.put("XL",XL);
        map.put("XC",XC);
        map.put("CD",CD);
        map.put("CM",CM);
        
        // 충돌 쌍 추가
        IV.crashList.add(IX);
        IX.crashList.add(IV);
        XL.crashList.add(XC);
        XC.crashList.add(XL);
        CD.crashList.add(CM);
        CM.crashList.add(CD);

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s1 = br.readLine();
        String s2 = br.readLine();
        int n1 = getNum(s1);
        int n2 = getNum(s2);
        System.out.println(n1+n2);
        System.out.println(convertString(n1+n2));
    }
}