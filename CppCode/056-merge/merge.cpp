//
// Created by shuai on 2023/9/3.
//
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int L = intervals[0][0];
        int R = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(R >= intervals[i][0]) {
                if(intervals[i][1] > R) {
                    R = intervals[i][1];
                }
            } else {
                res.push_back({L, R});
                L = intervals[i][0];
                R = intervals[i][1];
            }
        }
        res.push_back({L, R});
        return res;
    }
};