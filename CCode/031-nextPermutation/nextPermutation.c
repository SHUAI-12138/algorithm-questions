//
// Created by shuai on 2023/8/18.
//
#include<stdlib.h>

int cmp(const void* e1, const void* e2) {
    return *(int*)e1 - *(int*)e2;
}

void swap(int* nums, int e1, int e2) {
    int temp = nums[e1];
    nums[e1] = nums[e2];
    nums[e2] = temp;
}

void nextPermutation(int* nums, int numsSize){
    if(numsSize < 2) return;
    if(numsSize == 2) {
        swap(nums, 0, 1);
        return;
    }
    int i = numsSize - 1;
    while(i > 0 && nums[i] <= nums[--i]);
    if(!i && nums[0] >= nums[1]) {
        qsort(nums, numsSize, sizeof(nums[0]), cmp);
        return;
    }
    int j = numsSize;
    while(nums[i] >= nums[--j]);
    swap(nums, i, j);
    // for(int left = i + 1, right = numsSize - 1; left < right; left++, right--) {
    //     swap(nums, left, right);
    // }
    qsort(nums + i + 1, numsSize - i - 1, sizeof(nums[0]), cmp);
}