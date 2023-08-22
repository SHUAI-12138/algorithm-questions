//
// Created by shuai on 2023/8/22.
//


int searchInsert(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
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