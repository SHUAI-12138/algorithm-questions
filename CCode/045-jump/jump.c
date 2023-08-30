//
// Created by shuai on 2023/8/28.
//

int jump(int* nums, int numsSize){
    if(numsSize < 2) return 0;
    int step = 0, cur = 0;
    int step_length = 0;
    while(cur <= numsSize - 1) {
        step_length = nums[cur];
        if(cur + step_length >= numsSize - 1) return step + 1;
        if(step_length == 1) {
            cur++;
            step++;
            continue;
        }
        int longest = step_length + cur;
        int pre = longest;
        for(int i = 1; i <= step_length; i++) {
            int tmp = nums[i + cur] + cur + i;
            if(tmp > longest) {
                longest = tmp;
                pre = i + cur;
            }
        }
        cur = pre;
        step++;
    }
    return step;
}
