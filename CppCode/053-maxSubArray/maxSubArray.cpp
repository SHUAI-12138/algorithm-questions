//
// Created by shuai on 2023/8/31.
//
#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, res = nums[0];
        for(auto i : nums) {
            if(pre > 0) {
                pre += i;
            } else {
                pre = i;
            }
            res = max(pre, res);
        }
        return res;
    }
};