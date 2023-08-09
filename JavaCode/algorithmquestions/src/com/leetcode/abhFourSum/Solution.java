package com.leetcode.abhFourSum;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<>();
        if(nums == null || nums.length < 4) {
            return result;
        }
        Arrays.sort(nums);
        // System.out.println(Arrays.toString(nums));
        for(int i = 0; i < nums.length - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            for(int j = i + 1; j < nums.length - 2; j++) {

                if(j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1;
                int right = nums.length - 1;
                while(left < right) {
                    long sum = nums[i] + nums[j] + nums[left] + nums[right];
                    // System.out.println(i + " " + j + " " + left + " " + right + " " + sum);
                    if(sum == target) {
                        List<Integer> temp = new ArrayList<>();
                        temp.add(nums[i]);
                        temp.add(nums[j]);
                        temp.add(nums[left]);
                        temp.add(nums[right]);
                        result.add(temp);
                        while(left < right && nums[left] == nums[++left]);
                        while(right > left && nums[right] == nums[--right]);
                    } else if(sum < target) {
                        left++;
                    } else {
                        right--;
                    }

                }
            }
        }

        return result;
    }
}