package com.leetcode.aefJump;

class Solution {
    public int jump(int[] nums) {
        int len = nums.length;
        if(len < 2) return 0;
        int step = 0, cur = 0;
        while(cur < len - 1) {
            int stepLen = nums[cur];
            if(stepLen + cur >= len - 1) return step + 1;
            if(stepLen == 1) {
                cur++;
                step++;
                continue;
            }
            int longest = cur + stepLen;
            int pre = cur + stepLen;
            for(int i = 1; i <= stepLen; i++) {
                int tmp = nums[cur + i] + i + cur;
                if(tmp > longest) {
                    longest = tmp;
                    pre = i + cur;
                }
            }
            cur = pre;
            ++step;
        }
        return step;
    }
}



// 动态规划
class SolutionByDP {
    public int jump(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        for(int i = 0; i < n; i++) {
            dp[i] = 2147483647;
        }
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 1; i + j < n && j <= nums[i]; j++) {
                dp[i + j] = Math.min(dp[i + j], dp[i] + 1);
            }
        }
        return dp[n - 1];
    }
}