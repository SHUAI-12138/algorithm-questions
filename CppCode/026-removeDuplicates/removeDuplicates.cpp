//
// Created by shuai on 2023/8/14.
//

#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = 0;
        int p = 1;
        int len = nums.size();
        while(p < len) {
            if(nums[cur] == nums[p]) {
                p++;
            } else {
                nums[++cur] = nums[p++];
            }
        }

        return ++cur;
    }
};