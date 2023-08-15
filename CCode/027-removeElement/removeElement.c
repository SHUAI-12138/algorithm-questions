//
// Created by shuai on 2023/8/14.
//

int removeElement(int* nums, int numsSize, int val){
    int cur = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != val && i == cur) {
            cur++;
        } else if(nums[i] != val && i != cur) {
            nums[cur++] = nums[i];
        }
    }

    return cur;
}
