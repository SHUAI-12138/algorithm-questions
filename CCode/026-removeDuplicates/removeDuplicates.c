//
// Created by shuai on 2023/8/14.
//


int removeDuplicates(int* nums, int numsSize){
    int length = 1;
    int cur = 0;
    int p = 1;
    while(p < numsSize) {
        if(nums[cur] == nums[p]) {
            p++;
        } else {
            nums[++cur] = nums[p++];
            length++;
        }
    }

    return length;
}