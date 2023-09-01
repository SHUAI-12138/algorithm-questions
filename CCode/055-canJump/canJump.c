//
// Created by shuai on 2023/9/1.
//
#include<stdbool.h>

int max(int a, int b) {
    return a > b ? a : b;
}

bool canJump(int* nums, int numsSize){
    int length = 0;
    bool res = true;
    for(int i = 0; i < numsSize; i++) {
        if(i > length) return false;
        //if(nums[i] == 0 && length == i && i != nums.length - 1) return false;
        length = max(length, i + nums[i]);
    }
    return true;
}