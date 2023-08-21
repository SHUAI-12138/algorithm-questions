//
// Created by shuai on 2023/8/21.
//

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    static int lower_bound(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            if(target <= nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    static vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> res;
        res.push_back(lower_bound(nums, target));
        if(res[0] == len || nums[res[0]] != target) return vector<int> {-1, -1};
        res.push_back(lower_bound(nums, target + 1) - 1);
        return res;
    }
};

int main() {
    vector<int> nums{1, 2};
    int target = 1;
    vector<int> res = Solution::searchRange(nums, target);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}