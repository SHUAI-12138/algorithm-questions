package com.leetcode.adaNextPermutation;


import java.util.Arrays;

class Solution {
    static void swap(int[] arr, int e1, int e2) {
        int temp = arr[e1];
        arr[e1] = arr[e2];
        arr[e2] = temp;
    }
    public void nextPermutation(int[] nums) {
        int i = nums.length - 1;
        while(i > 0 && nums[i] <= nums[--i]);
        if(i == 0 && nums[0] >= nums[1]) {
            Arrays.sort(nums);
            return;
        }
        int j = nums.length;
        while(nums[i] >= nums[--j]);
        swap(nums, i, j);
        for(int left = i + 1, right = nums.length - 1; left < right; left++, right--) {
            swap(nums, left, right);
        }
    }

    public static void main(String[] args) {
        int[] arr = new int[]{5, 1, 1};
        Solution solution = new Solution();
        solution.nextPermutation(arr);
    }
}
