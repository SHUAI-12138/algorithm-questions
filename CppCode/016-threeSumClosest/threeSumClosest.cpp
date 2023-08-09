
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();

        sort(nums.begin(), nums.end());
        int sum = 100000;
        int temp = 0;
        int left = 0;
        int right = 0;
        if (nums[0] + nums[1] + nums[2] >= target)
		    return nums[0] + nums[1] + nums[2];
	    if (nums[len - 1] + nums[len - 2] + nums[len - 3] <= target)
		    return nums[len - 1] + nums[len - 2] + nums[len - 3];

        for(int k = 0; k < len - 2; k++) {
            left = k + 1;
            right = len - 1;
            while(left < right) {
                temp = nums[k] + nums[left] + nums[right];
                if(temp == target) return target;
                sum = abs(sum - target) <= abs(temp - target) ? sum : temp;
                if(temp > target) {
                    while(right > left && nums[right] == nums[--right]);
                } else {
                    while(left < right && nums[left] == nums[++left]);
                }
                 
            }
        }

        return sum;
    }
};