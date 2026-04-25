import java.util.*;

class Main {
    public static void main(String[] l) throws Exception {
        int peopleCount=0,tmp;
        while((tmp = System.in.read()) > 32) {
            peopleCount = (peopleCount<<3)+(peopleCount<<1)+(tmp&15);
        }
        ArrayList<Integer> arr = new ArrayList<>(peopleCount);
        for (int i = 1; i <= peopleCount; i++) {
            arr.add(i);
        }
        // 총 필요한 단계 : 6명이면 1단계부터 5단계 수행하면 한명만 남는다
        long round = 1,curSize,removeIndex;
        long curIndex = 0;
        while ((curSize = arr.size()) > 1) {
            removeIndex = curIndex+(round*round*round)-1;
            if (removeIndex >= curSize) removeIndex = removeIndex%curSize;
            arr.remove((int)removeIndex);
            curIndex = removeIndex == arr.size() ? 0 : removeIndex;
            round++;
        }
        System.out.println(arr.get(0));
    }
}