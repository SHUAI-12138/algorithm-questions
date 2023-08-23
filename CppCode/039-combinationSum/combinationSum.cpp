//
// Created by shuai on 2023/8/22.
//

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:

    void backstracking(vector<vector<int>>& res, vector<int>& addend, vector<int>& candidates, int target, int pos) {
        if(pos >= candidates.size()) return;
        if(candidates[pos] == target) {
            addend.push_back(candidates[pos]);
            res.push_back(addend);
            addend.pop_back();
        }

        if(target > candidates[pos]) {
            addend.push_back(candidates[pos]);
            backstracking(res, addend, candidates, target - candidates[pos], pos);
            addend.pop_back();
        }
        backstracking(res, addend, candidates, target, pos + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> addend;
        backstracking(res, addend, candidates, target, 0);
        return res;
    }
};

class SolutionBySort {
public:

    void backstracking(vector<vector<int>>& res, vector<int>& addend, vector<int>& candidates, int target, int pos) {
        if(pos >= candidates.size()) return;
        if(candidates[pos] > target) return;
        if(candidates[pos] == target) {
            addend.push_back(candidates[pos]);
            res.push_back(addend);
            addend.pop_back();
            return;
        }
        backstracking(res, addend, candidates, target, pos + 1);
        addend.push_back(candidates[pos]);
        target -= candidates[pos];
        backstracking(res, addend, candidates, target, pos);
        addend.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        if(target < candidates[0]) return res;
        vector<int> addend;
        backstracking(res, addend, candidates, target, 0);
        return res;
    }
};


int main() {
    vector<int> candiates{7, 3, 9, 6};
    Solution solution;
    vector<vector<int>> res = solution.combinationSum(candiates, 6);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
