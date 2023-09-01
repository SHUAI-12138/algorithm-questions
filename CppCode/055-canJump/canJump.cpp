//
// Created by shuai on 2023/9/1.
//
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = 0;
        bool res = true;
        for(int i = 0; i < nums.size(); i++) {
            if(i > length) return false;
            length = max(length, i + nums[i]);
            //if(nums[i] == 0 && length == i && i != nums.size() - 1) return false;
        }
        return true;
    }
};