package com.leetcode.addSearchRange;

class Solution {

    public static int lower_bound(int[] nums, int target) {
        int len = nums.length;
        int left = 0;
        int right = len - 1;
        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    public int[] searchRange(int[] nums, int target) {
        int leftIndex = lower_bound(nums, target);
        if(leftIndex == nums.length || nums[leftIndex] != target) return new int[]{-1, -1};
        int rightIndex = lower_bound(nums, target + 1) - 1;
        return new int[]{leftIndex, rightIndex};
    }
}