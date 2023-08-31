package com.leetcode.afcTotalNQueens;

class Solution {
    private static int res;
    public int totalNQueens(int n) {
        int full = 1;
        for(int i = 0; i < n - 1; i++) {
            full = (full << 1) | 1;
        }
        res = 0;
        backstracking(0, 0, 0, full, n, 0);
        return res;
    }

    public void backstracking(int left, int chosen, int right, int full, int n, int cur) {
        if(cur == n) {
            res++;
        }
        int x = left | chosen | right;
        if(x == full) return;
        int chose = (full + 1) >> 1;
        for(int i = 0; i < n; i++, chose >>= 1) {
            if((x & chose) > 0) continue;
            backstracking((left | chose) << 1, chosen | chose , (right | chose) >> 1, full, n, cur + 1);
        }
    }
}
