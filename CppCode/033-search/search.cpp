//
// Created by shuai on 2023/8/19.
//

#include<vector>

using namespace std;

class Solution {
public:

    int findMin(vector<int>& nums) {
        int len = nums.size();
        if(len == 2) return nums[0] < nums[1] ? 0 : 1;
        if(nums[0] < nums[len - 1]) {
            return 0;
        }
        int left = 0;
        int right = len - 1;
        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            if(nums[mid] < nums[mid - 1]) {
                return mid;
            } else if(mid + 1 < len && nums[mid] > nums[mid + 1]) {
                return mid + 1;
            }
            if(nums[mid] > nums[0]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(!len) return -1;
        if(len == 1) return target == nums[0] ? 0 : -1;
        if(len == 2) return target == nums[0] ? 0 : (target == nums[1] ? 1 : -1);
        int n = findMin(nums);
        if(nums[n] == target) return n;
        int left = 0;
        int right = 0;
        if(target > nums[0]) {
            left = 0;
            right = n == 0 ? len - 1 : n - 1;
        } else if(target == nums[0]) {
            return 0;
        } else {
            if(n == 0) return -1;
            left = n;
            right = len - 1;
        }
        while(1) {
            int mid = (left + right) >> 1;
            if(target > nums[mid]) {
                left = mid;
            } else if(target == nums[mid]) {
                return mid;
            } else {
                right = mid;
            }
            if(left + 1 >= right) break;
        }
        if(nums[left] == target) return left;
        if(nums[right] == target) return right;
        return -1;
    }
};