//
// Created by shuai on 2023/8/28.
//
#include<vector>

using namespace std;

class Solution {
public:

    void backstracking(vector<int>& nums, vector<int>& map, vector<vector<int>>& res, vector<int>& ans, int count) {
        if(count == nums.size()) {
            res.push_back(ans);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(map[i]) continue;
            ans.push_back(nums[i]);
            map[i] = 1;
            backstracking(nums, map, res, ans, count + 1);
            ans.pop_back();
            map[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        vector<int> map(nums.size(), 0);
        backstracking(nums, map, res, ans, 0);
        return res;
    }
};