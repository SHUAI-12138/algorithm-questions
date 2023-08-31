//
// Created by shuai on 2023/8/31.
//

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    void fill(vector<vector<string>>& res, vector<int>& ans, int n) {
        vector<string> tmp;
        for(int i = 0; i < n; i++) {
            char ch[n + 1];
            ch[n] = '\0';
            for(int j = 0; j < n; j++) {
                if(j == ans[i]) {
                    ch[j] = 'Q';
                } else {
                    ch[j] = '.';
                }
            }
            tmp.push_back(ch);
        }
        res.push_back(tmp);
    }

    void backstracking(vector<vector<string>>& res, vector<int>& ans, int left, int right, int chosen, int full, int n) {
        if(ans.size() == n) {
            fill(res, ans, n);
            return;
        }
        int x = left | right | chosen;
        if(x == full) return;
        int chose = ((full + 1) >> 1);
        for(int i = 0; i < n; i++, chose >>= 1) {
            if(x & chose) continue;
            ans.push_back(i);
            backstracking(res, ans, (left | chose) << 1 & full, (right | chose) >> 1 & full, chosen | chose, full, n);
            ans.pop_back();
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        int full = 1;
        for(int i = 0; i < n - 1; i++) {
            full = (full << 1 | 1);
        }
        vector<vector<string>> res;
        if(n == 2 || n == 3) return res;
        vector<int> ans;
        backstracking(res, ans, 0, 0, 0, full, n);
        return res;
    }
};