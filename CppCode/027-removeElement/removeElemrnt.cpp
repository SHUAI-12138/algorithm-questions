//
// Created by shuai on 2023/8/14.
//

#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cur = 0;
        int len = nums.size();
        for(int i = 0; i < len; i++) {
            if(nums[i] != val && i == cur) {
                cur++;
            } else if(nums[i] != val && i != cur) {
                nums[cur++] = nums[i];
            }
        }

        return cur;
    }
};