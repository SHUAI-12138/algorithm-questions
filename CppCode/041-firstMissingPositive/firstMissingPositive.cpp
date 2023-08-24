//
// Created by shuai on 2023/8/24.
//

#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        int max = len + 1;
        for(int i = 0; i < len; i++) {
            if(nums[i] <= 0) {
                nums[i] = max;
            }
        }
        for(int i = 0; i < len; i++) {
            int tmp = abs(nums[i]);
            if(tmp < max && nums[tmp - 1] > 0) {
                nums[tmp - 1] = -nums[tmp - 1];
            }
        }
        for(int i = 0; i < len; i++) {
            if(nums[i] > 0) {
                return i + 1;
            }
        }
        return max;
    }
};