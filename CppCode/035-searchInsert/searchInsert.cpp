//
// Created by shuai on 2023/8/22.
//

#include<vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            if(nums[mid] < target) {
                left = mid + 1;
            } else if(nums[mid] > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return left;
    }
};