import java.util.*;
class Solution {
    public int solution(int[] nums) {
        int answer = (int)Arrays.stream(nums).distinct().count();
        answer = Math.min(answer,nums.length/2);
        return answer;
    }
}