package com.leetcode.afdMaxSubArray;

class Solution {
    public int maxSubArray(int[] nums) {
        int pre = 0, res = nums[0];
        for(var i : nums) {
            if(pre > 0) {
                pre += i;
            } else {
                pre = i;
            }
            if(pre > res) res = pre;
        }
        return res;
    }
}