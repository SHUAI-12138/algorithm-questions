
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int len = nums.size();
        if(len < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            if((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;

            for(int j = i + 1; j < len - 2; j++) {
                if(nums[j] == nums[j - 1] && j > i + 1) continue;

                int left = j + 1;
                int right = len - 1;
                while(left < right) {
                    long sum = nums[i] + nums[j] + nums[left] + nums[right];
                    // cout << i << " " << j << " " << left << " " << right << " " << sum << endl;
                    if(sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
                        result.push_back(temp);
                        while(left < right && nums[left] == nums[++left]);
                        while(right > left && nums[right] == nums[--right]);
                    } else if(sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }

            }
        }

        return result;
    }
};