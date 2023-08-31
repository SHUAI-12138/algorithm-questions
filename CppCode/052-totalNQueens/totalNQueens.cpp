//
// Created by shuai on 2023/8/31.
//



static int res;

class Solution {
public:

    void backstracking(int left, int chosen, int right, int full, int cur, int n) {
        if(cur == n) {
            res++;
            return;
        }
        int x = left | chosen | right;
        if(x == full) return;
        int chose = (full + 1) >> 1;
        for(int i = 0; i < n; i++, chose >>= 1) {
            if(x & chose) continue;
            backstracking((left | chose) << 1, chosen | chose, (right | chose) >> 1, full, cur + 1, n);
        }
    }

    int totalNQueens(int n) {
        int full = 1;
        for(int i = 0; i < n - 1; i++) {
            full = (full << 1) | 1;
        }
        res = 0;
        backstracking(0, 0, 0, full, 0, n);
        return res;
    }
};