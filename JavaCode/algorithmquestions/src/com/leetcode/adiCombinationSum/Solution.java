package com.leetcode.adiCombinationSum;

import java.util.*;

class Solution {
    public static void backstracking(List<List<Integer>> res, LinkedList<Integer> ans, int[] candidates, int target, int pos) {
        if(pos >= candidates.length) return;
        if(candidates[pos] == target) {
            ans.add(candidates[pos]);
            List<Integer> tmp = new ArrayList<>();
            var iterator = ans.listIterator();
            while(iterator.hasNext()) {
                tmp.add(iterator.next());
            }
            res.add(tmp);
            ans.removeLast();
        }
        if(candidates[pos] < target) {
            ans.add(candidates[pos]);
            backstracking(res, ans, candidates, target - candidates[pos], pos);
            ans.removeLast();
        }
        backstracking(res, ans, candidates, target, pos + 1);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        LinkedList<Integer> ans = new LinkedList<>();
        backstracking(res, ans, candidates, target, 0);
        return res;
    }
}