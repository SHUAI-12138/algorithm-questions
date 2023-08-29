package com.leetcode.aegPermute;

import java.util.List;
import java.util.ArrayList;

class Solution {
    public void backstracking(int[] nums, boolean[] map, List<List<Integer>> res, ArrayList<Integer> ans, int count) {
        if(count == nums.length) {
            res.add(new ArrayList<Integer>(ans));
            return;
        }
        for(int i = 0; i < nums.length; i++) {
            if(map[i]) continue;
            ans.add(nums[i]);
            map[i] = true;
            backstracking(nums, map, res, ans, count + 1);
            ans.remove(ans.size() - 1);
            map[i] = false;
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        boolean[] map = new boolean[nums.length];
        List<List<Integer>> res = new ArrayList<>();
        if(nums.length == 1) {
            res.add(new ArrayList<Integer>(){{
                add(nums[0]);
            }});
            return res;
        }
        ArrayList<Integer> ans = new ArrayList<>();
        backstracking(nums, map, res, ans, 0);
        return res;
    }
}