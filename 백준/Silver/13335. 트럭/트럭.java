import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;

class Main {
    public static void main(String[] l) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] artmp = br.readLine().split(" ");
        final int N = Integer.parseInt(artmp[0]);
        final int bridgeLength = Integer.parseInt(artmp[1]);
        final int maxWeight = Integer.parseInt(artmp[2]);
        int nextCarIndex = 0,nextCarWeight;
        int[] weightArr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        HashMap<Integer,Integer> removalTime = new HashMap<>();
        int currentTime = 1;
        int bridgeCurrentWeightSum = 0;
        for (nextCarIndex = 0; ; currentTime++) {
            if (removalTime.containsKey(currentTime)) {
                bridgeCurrentWeightSum-=removalTime.remove(currentTime); // 제거
            }
            if (nextCarIndex >= weightArr.length) {
                if (removalTime.isEmpty()) {
                    break;
                }
                continue;
            }
            nextCarWeight = weightArr[nextCarIndex];
            if (nextCarWeight + bridgeCurrentWeightSum > maxWeight) continue; // 진행 안함
            removalTime.put(currentTime+bridgeLength,nextCarWeight);
            bridgeCurrentWeightSum += nextCarWeight;
            nextCarIndex++;
        }
        System.out.println(currentTime);
    }
}