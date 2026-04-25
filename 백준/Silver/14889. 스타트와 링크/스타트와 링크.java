import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static int[][] arr;
    static int N;
    static int maxTeamSize;
    static int bitCount; // 6명이면 6자리
    static LinkedHashSet<Integer> set1 = new LinkedHashSet();
    static LinkedHashSet<Integer> set2 = new LinkedHashSet();
    public static void main(String[] l) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int n = Integer.parseInt(br.readLine());
        N = n;
        maxTeamSize = n/2;
        arr = new int[N][];
        for (int i = 0; i < N; i++) {
            arr[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }

        int tmp = 1;
        bitCount = N; // 6명이면 총 비트는 6자리
        int startBit; // 6명이면 000111부터 시작 = 2^4-1
        for (int i = 0; i < maxTeamSize; i++) {
            tmp = tmp*2;
        }
        startBit = tmp-1; // 000111
        set1.add(startBit);
        set2.add(getOtherTeamBit(startBit));
        int lastTeam = startBit^(1 << bitCount-1); // 마지막 팀은 000111과 111111을 XOR하면 된다
        int nextTeam = startBit+1;
        while (lastTeam != nextTeam) {
            nextTeam++;
            if (getBitCount(nextTeam) == maxTeamSize) { // 1이 3개 있는 경우
                int otherTeam = getOtherTeamBit(nextTeam);
                if (set1.contains(otherTeam) || set1.contains(nextTeam) || set2.contains(otherTeam) || set2.contains(nextTeam)) continue;
                set1.add(nextTeam);
                set2.add(otherTeam);
            }
        }
        int t1,t2;
        int[] arr1,arr2;
        Iterator<Integer> it1 = set1.iterator();
        Iterator<Integer> it2 = set2.iterator();
        int minGap = Integer.MAX_VALUE;
        while (it1.hasNext()) {
            t1 = it1.next();
            t2 = it2.next();
            arr1 = getIndexArr(t1);
            arr2 = getIndexArr(t2);
            minGap = Math.min(minGap,getTeamAbilityGap(arr1,arr2));
        }
        System.out.println(minGap);
    }

    private static int[] getIndexArr(int t){
        int[] arr = new int[maxTeamSize];
        String s = Integer.toBinaryString(t);
        int zeroAppendCount = N-s.length();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < zeroAppendCount; i++) {
            sb.append("0");
        }
        s = sb+s;
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                arr[j] = i;
                j++;
            }
        }
        return arr;
    }

    private static int getOtherTeamBit(int team) {
        int tmp = 1;
        tmp = (tmp << bitCount)-1; // 6명이면 111111이므로, 1을 6번 밀면 1000000인데 거기서 1을 빼면 111111
        return tmp^team;  // XOR연산
    }

    public static int getBitCount(int input) {
        int count = 0;
        int mask = 1 << 31;
        while (true){
            if (mask == 0){
                break;
            }
            if((mask & input) == 0){

            } else {
                count++;
            }
            mask = mask >>> 1;
        }
        return count;
    }


    private static int getTeamAbilityGap(int[] a1, int[] a2) {
        int sum_1 =0;
        int sum_2 =0;
        int t1,t2,t3,t4;
        for (int i = 0; i < a1.length; i++) {
            t1 = a1[i];
            t3 = a2[i];
            for (int j = 0; j < a1.length; j++) {
                t2 = a1[j];
                t4 = a2[j];
                sum_1 += arr[t1][t2];
                sum_2 += arr[t3][t4];
            }
        }
        return Math.abs(sum_1-sum_2);
    }

}