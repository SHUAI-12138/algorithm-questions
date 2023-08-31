//
// Created by shuai on 2023/8/31.
//


int maxSubArray(int* nums, int numsSize){
    int pre = 0, res = nums[0];
    for(int i = 0; i < numsSize; i++) {
        if(pre > 0) {
            pre += nums[i];
        } else {
            pre = nums[i];
        }
        if(pre > res) res = pre;
    }
    return res;
}