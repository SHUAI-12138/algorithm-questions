package com.leetcode.acfRemoveDuplicates;

class Solution {
    public int removeDuplicates(int[] nums) {
        int length = 1;
        int cur = 0;
        int p = 1;
        while(p < nums.length) {
            if(nums[cur] == nums[p]) {
                p++;
            } else {
                nums[++cur] = nums[p++];
                length++;
            }
        }

        return length;
    }
}
