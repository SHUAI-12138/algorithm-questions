package com.leetcode.acgRemoveElement;

class Solution {
    public int removeElement(int[] nums, int val) {
        int cur = 0;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] != val && cur == i) {
                cur++;
            } else if(nums[i] != val && cur != i) {
                nums[cur++] = nums[i];
            }
        }

        return cur;
    }
}