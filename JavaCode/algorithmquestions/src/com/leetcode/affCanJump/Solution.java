package com.leetcode.affCanJump;


class Solution {
    public boolean canJump(int[] nums) {
        if(nums.length == 1) return true;
        boolean res = true;
        for(int i = nums.length - 1; i >= 0; i--) {
            if(nums[i] == 0) {
                res = false;
                for(int j = i - 1; j >= 0; j--) {
                    if(nums[j] > i - j || (i == nums.length - 1 && nums[j] >= i - j)) {
                        res = true;
                        break;
                    }
                }
                if(!res) return false;
            }
        }
        return res;
    }

}

class SolutionSlower {
    public boolean canJump(int[] nums) {
        int length = 0;
        boolean res = true;
        for(int i = 0; i < nums.length; i++) {
            if(i > length) return false;
            //if(nums[i] == 0 && length == i && i != nums.length - 1) return false;
            length = Math.max(length, i + nums[i]);
        }
        return true;
    }
}