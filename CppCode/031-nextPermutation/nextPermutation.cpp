//
// Created by shuai on 2023/8/18.
//

#include<vector>
#include<algorithm>

using namespace std;



class Solution {
public:
    void swap(vector<int>& arr, int e1, int e2) {
        int temp = arr[e1];
        arr[e1] = arr[e2];
        arr[e2] = arr[e1];
    }
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return;
        if(len == 2) {
            swap(nums, 0, 1);
            return;
        }
        int i = len - 1;
        while(i > 0 && nums[i] <= nums[--i]);
        if(!i && nums[0] >= nums[1]) {
            sort(nums.begin(), nums.end());
            return;
        }
        int j = len;
        while(nums[i] >= nums[--j]);
        swap(nums, i, j);
        for(int left = i + 1, right = len - 1; left < right; left++, right--) {
            swap(nums, left, right);
        }
    }
};

int main() {
    vector<int> nums{1, 2, 3};
    Solution solution;
    solution.nextPermutation(nums);
}