package com.leetcode.aagReverse;

public class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.reverse(-123));
    }

    public int reverse(int x) {
        if(x < 10 && x > -10) {
            return x;
        }
        int sum = 0;
        int num = x;
        while(num != 0) {
            if((sum == 214748364 && num > 7) || sum > 214748364) {
                return 0;
            }
            if((sum == -214748364 && num < -8) || sum < -214748364) {
                return 0;
            }
            sum = sum * 10 + num % 10;
            num /= 10;
        }
        return sum;
    }

}
