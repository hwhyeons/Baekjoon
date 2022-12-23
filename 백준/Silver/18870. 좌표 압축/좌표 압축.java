import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

class Node {
    static int nextIndexOrigin = 0;
    static int nextIndexSorted = 0;
    static int beforeNumber = Integer.MIN_VALUE;
    static int beforeSameCount = 0;
    int val;
    int indexOrigin;
    int answer;
    public static Node makeNode(int val){
        Node n = new Node();
        n.val = val;
        n.indexOrigin = nextIndexOrigin;
        ++nextIndexOrigin;
        return n;
    }

    public void setAnswer() {
        if (beforeNumber == this.val) {
            this.answer = nextIndexSorted-(++beforeSameCount);
        } else {
            this.answer = nextIndexSorted-beforeSameCount;
            beforeNumber = this.val;
        }
        ++nextIndexSorted;
    }

    public int getIndexOrigin(){
        return this.indexOrigin;
    }

    public int getVal(){
        return this.val;
    }
}
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int COUNT = Integer.parseInt(br.readLine());
        String answer = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt)
                        .mapToObj(Node::makeNode).sorted(Comparator.comparing(Node::getVal))
                .peek(Node::setAnswer).sorted(Comparator.comparing(Node::getIndexOrigin))
                .map(node->String.valueOf(node.answer)).collect(Collectors.joining(" "));
        System.out.println(answer);
    }
}
