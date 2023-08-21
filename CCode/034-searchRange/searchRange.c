

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include<stdlib.h>

int lower_bound(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    while(left <= right) {
        int mid = left + ((right - left) >> 1);
        if(nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * 2);
    (*returnSize) = 2;
    res[0] = lower_bound(nums, numsSize, target);
    if(res[0] == numsSize || nums[res[0]] != target) {
        res[0] = -1;
        res[1] = -1;
        return res;
    }
    res[1] = lower_bound(nums, numsSize, target + 1) - 1;
    return res;
}