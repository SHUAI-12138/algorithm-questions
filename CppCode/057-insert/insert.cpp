//
// Created by shuai on 2023/9/3.
//
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int L = newInterval[0];
        int R = newInterval[1];
        bool flag = true;
        for(const auto& interval : intervals) {
            if(R < interval[0]) {
                if(flag) {
                    ans.push_back({L, R});
                    flag = false;
                }
                ans.push_back(interval);
            } else if(L > interval[1]) {
                ans.push_back(interval);
            } else {
                L = min(L, interval[0]);
                R = max(R, interval[1]);
            }
        }
        if(flag) {
            ans.push_back({L, R});
        }
        return ans;
    }
};