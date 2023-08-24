//
// Created by shuai on 2023/8/23.
//

#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    void backstracking(vector<vector<int>>& res, vector<int>& ans, vector<int>& candidates, int target, int pos) {
        if(target == 0) {
            res.push_back(ans);
            return;
        }
        if(pos >= candidates.size()) return;
        if(candidates[pos] > target) return;
        if(pos < candidates.size() - 1 && candidates[pos] == candidates[pos + 1]) {
            // 获取相同元素的数量
            int n = 2;
            while(pos + n < candidates.size() && candidates[pos + n] == candidates[pos]) {
                n++;
            }
            // 选自己，接着往下走
            ans.push_back(candidates[pos]);
            backstracking(res, ans, candidates, target - candidates[pos], pos + 1);
            ans.pop_back();

            // 不选自己，跳出去
            backstracking(res, ans, candidates, target, pos + n);
        } else {
            // 选自己
            ans.push_back(candidates[pos]);
            backstracking(res, ans, candidates, target - candidates[pos], pos + 1);
            ans.pop_back();
            // 不选自己
            backstracking(res, ans, candidates, target, pos + 1);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        backstracking(res, ans, candidates, target, 0);
        return res;
    }
};