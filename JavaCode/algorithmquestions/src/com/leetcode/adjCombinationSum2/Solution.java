package com.leetcode.adjCombinationSum2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

class Solution {

    public static void backstracking(List<List<Integer>> res, LinkedList<Integer> ans, int[] candidates, int target, int pos) {
        if(target == 0) {
            List<Integer> tmp = new ArrayList<>();
            var it = ans.listIterator();
            while(it.hasNext()) {
                tmp.add(it.next());
            }
            res.add(tmp);
        }
        if(pos >= candidates.length) return;
        if(candidates[pos] > target) return;

        // 如果连续相等，选 0, 1， 2， …… ，n 个
        if(pos < candidates.length - 1 && candidates[pos] == candidates[pos + 1]) {
            int n = 2;
            while(pos + n < candidates.length && candidates[pos] == candidates[pos + n]) {
                n++;
            }
            // 选自己，接着走
            ans.add(candidates[pos]);
            backstracking(res, ans, candidates, target - candidates[pos], pos + 1);
            ans.removeLast();
            // 不选自己，跳出去
            backstracking(res, ans, candidates, target, pos + n);
        } else {
            // 选自己
            ans.add(candidates[pos]);
            backstracking(res, ans, candidates, target - candidates[pos], pos + 1);
            ans.removeLast();
            // 不选自己
            backstracking(res, ans, candidates, target, pos + 1);
        }
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        LinkedList<Integer> ans = new LinkedList<>();
        Arrays.sort(candidates);
        backstracking(res, ans, candidates, target, 0);
        return res;
    }
}
