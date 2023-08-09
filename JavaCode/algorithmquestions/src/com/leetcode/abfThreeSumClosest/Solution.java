package com.leetcode.abfThreeSumClosest;

import java.util.Arrays;

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int len = nums.length;
        Arrays.sort(nums);

        int sum = 100000;
        int left = 0;
        int temp = 0;
        int right = 0;
        if (nums[0] + nums[1] + nums[2] >= target)
            return nums[0] + nums[1] + nums[2];
        if (nums[len - 1] + nums[len - 2] + nums[len - 3] <= target)
            return nums[len - 1] + nums[len - 2] + nums[len - 3];

        for(int k = 0; k < len - 2; k++) {
            left = k + 1;
            right = len - 1;
            while(left < right) {
                temp = nums[k] + nums[left] + nums[right];
                if(temp == target) return target;
                sum = Math.abs(sum - target) <= Math.abs(temp - target) ? sum : temp;
                if(temp < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return sum;
    }
}
