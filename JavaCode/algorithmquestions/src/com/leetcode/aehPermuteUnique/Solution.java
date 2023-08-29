package com.leetcode.aehPermuteUnique;

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public void backstracking(int[] nums, List<List<Integer>> res, List<Integer> ans, boolean[] map, int count) {
        if(count == nums.length) {
            res.add(new ArrayList<Integer>(ans));
            return;
        }
        for(int i = 0; i < nums.length; i++) {
            // 相同的按照顺序，可以避免重复
            if(map[i] || (i > 0 && nums[i] == nums[i - 1] && !map[i - 1])) continue;
            ans.add(nums[i]);
            map[i] = true;
            backstracking(nums, res, ans, map, count + 1);
            ans.remove(ans.size() - 1);
            map[i] = false;
        }
    }
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> ans = new ArrayList<>();
        boolean[] map = new boolean[nums.length];
        backstracking(nums, res, ans, map, 0);
        return res;
    }
}
