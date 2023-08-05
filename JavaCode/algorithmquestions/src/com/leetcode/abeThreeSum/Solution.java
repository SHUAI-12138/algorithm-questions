package com.leetcode.abeThreeSum;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int len = nums.length;
        List<List<Integer>> res = new ArrayList<>();

        for(int k = 0; k <= len - 3 && nums[k] <= 0; k++) {
            if (k > 0 && nums[k] == nums[k - 1]) continue; // 循环到不一样的值，防止重复
            int left = k + 1;
            int right = len - 1;
            while(left < right) {
                int sum = nums[left] + nums[right] + nums[k];
                if(sum < 0) {
                    left++;
                } else if(sum > 0) {
                    right--;
                } else {
                    List<Integer> temp = new ArrayList<>();
                    temp.add(nums[k]);
                    temp.add(nums[left]);
                    temp.add(nums[right]);
                    res.add(temp);
                    while(left + 1 < right && nums[left] == nums[++left]); // 循环到下一个不一样的值，防止重复
                    while(right > left && nums[right] == nums[--right]);   // 循环到下一个不一样的值，防止重复
                }
            }
        }

        return res;
    }
}
