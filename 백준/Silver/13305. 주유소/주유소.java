import java.io.*;
import java.util.*;


class Node {
    long price; // 각 노드의 리터당 기름 값
    int accumulatedLen; // 해당 도시까지의 누적 거리

    public long getPrice() {
        return this.price;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int CITY_COUNT = Integer.parseInt(br.readLine());
        ArrayList<Node> arr = new ArrayList<>();

        // 도로 길이
        int[] len = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] pricePerLiter = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int accLen = 0;
        for (int i = 0; i < len.length; i++) {
            Node n = new Node();
            n.accumulatedLen = accLen;
            n.price = pricePerLiter[i];
            arr.add(n);
            accLen += len[i];
        }
        // 맨 마지막 노드만 따로 추가
        Node n = new Node();
        n.accumulatedLen = accLen;
        n.price = pricePerLiter[pricePerLiter.length-1];

        long sumPrice = 0; //  최종 가격

        // 리터당 가격이 싼 순서대로 나열
        Collections.sort(arr,Comparator.comparing(Node::getPrice));
        int maxLen = accLen; // maxLen 시작은 맨 마지막 거리가 최대로 구매한 거리
        for (Node node : arr){
            long price = node.getPrice();
            int accumulatedLen = node.accumulatedLen;
            if (maxLen < accumulatedLen) continue; // 이미 기름 다 구매해놓은 거리보다 더 멀리 있는 노드인 경우 스킵
            sumPrice += (maxLen-accumulatedLen)*price;
            maxLen = accumulatedLen; // 현재 까지 거리로 전환
            if (maxLen == 0) break;
        }
        System.out.println(sumPrice);
    }
}