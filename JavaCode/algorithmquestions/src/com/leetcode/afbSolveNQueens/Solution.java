package com.leetcode.afbSolveNQueens;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<List<String>> solveNQueens(int n) {
        int full = 1;
        for(int i = 0; i < n - 1; i++) {
            full = (full << 1) | 1;
        }
        int[] ans = new int[n];
        List<List<String>> res = new ArrayList<>();
        backstracking(res, ans, 0, 0, 0, full, n, 0);
        return res;
    }

    public void backstracking(List<List<String>> res, int[] ans, int left, int chosen, int right, int full, int n, int cur) {
        if(cur == n) {
            fill(res, ans, n);
        }
        int x = left | chosen | right;
        if(x == full) return;
        int chose = (full + 1) >> 1;
        for(int i = 0; i < n; i++, chose >>= 1) {
            if((x & chose) > 0) continue;
            ans[cur] = i;
            backstracking(res, ans, (left | chose) << 1, chosen | chose , (right | chose) >> 1, full, n, cur + 1);
        }
    }

    public void fill(List<List<String>> res, int[] ans, int n) {
        List<String> result = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            char[] tmp = new char[n];
            Arrays.fill(tmp, '.');
            tmp[ans[i]] = 'Q';
            result.add(new String(tmp));
        }
        res.add(result);
    }
}

class SolutionSlower {
    public List<List<String>> solveNQueens(int n) {
        int full = 1;
        for(int i = 0; i < n - 1; i++) {
            full = (full << 1) | 1;
        }
        LinkedList<Integer> ans = new LinkedList<>();
        List<List<String>> res = new ArrayList<>();
        backstracking(res, ans, 0, 0, 0, full, n);
        return res;
    }

    public void backstracking(List<List<String>> res, LinkedList<Integer> ans, int left, int chosen, int right, int full, int n) {
        if(ans.size() == n) {
            fill(res, ans, n);
        }
        int x = left | chosen | right;
        if(x == full) return;
        int chose = (full + 1) >> 1;
        for(int i = 0; i < n; i++, chose >>= 1) {
            if((x & chose) > 0) continue;
            ans.add(i);
            backstracking(res, ans, (left | chose) << 1, chosen | chose , (right | chose) >> 1, full, n);
            ans.removeLast();
        }
    }

    public void fill(List<List<String>> res, LinkedList<Integer> ans, int n) {
        List<String> result = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            char[] tmp = new char[n];
            Arrays.fill(tmp, '.');
            tmp[ans.get(i)] = 'Q';
            result.add(new String(tmp));
        }
        res.add(result);
    }
}
