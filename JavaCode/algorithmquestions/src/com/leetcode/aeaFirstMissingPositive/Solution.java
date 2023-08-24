package com.leetcode.aeaFirstMissingPositive;

class Solution {
    public int firstMissingPositive(int[] nums) {
        int len = nums.length;
        int max = len + 1;
        for(int i = 0; i < len; i++) {
            if(nums[i] <= 0) {
                nums[i] = max;
            }
        }
        for(int i = 0; i < len; i++) {
            int tmp = Math.abs(nums[i]);
            if(tmp < max && nums[tmp - 1] > 0) {
                nums[tmp - 1] = -nums[tmp - 1];
            }
        }
        for(int i = 0; i < len; i++) {
            if(nums[i] > 0) {
                return i + 1;
            }
        }
        return max;
    }
}
