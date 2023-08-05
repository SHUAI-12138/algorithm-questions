
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int k = 0; k < len - 2 && nums[k] <= 0; k++) {
            if(k > 0 && nums[k] == nums[k - 1]) continue;
            int left = k + 1;
            int right = len - 1;
            while(left < right) {
                int sum = nums[k] + nums[left] + nums[right];
                if(sum > 0) {
                    right--;
                } else if(sum < 0) {
                    left++;
                } else {
                    vector<int> temp = {nums[k], nums[left], nums[right]};
                    res.push_back(temp);
                    while(left + 1 < right && nums[k] == nums[++k]);
                    while(right > left && nums[right] == nums[--right]);
                }
            }
        }

        return res;
    }
};