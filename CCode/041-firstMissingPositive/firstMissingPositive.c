//
// Created by shuai on 2023/8/24.
//
#include<math.h>

int firstMissingPositive(int* nums, int numsSize){
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] <= 0) {
            nums[i] = numsSize + 1;
        }
    }
    for(int i = 0; i < numsSize; i++) {
        int tmp = abs(nums[i]);
        if(tmp <= numsSize && nums[tmp - 1] > 0) {
            nums[tmp - 1] = -nums[tmp - 1];
        }
    }
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] > 0) {
            return i + 1;
        }
    }
    return numsSize + 1;
}