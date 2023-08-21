//
// Created by shuai on 2023/8/19.
//


int findMin(int* nums, int numsSize) {
    if(numsSize == 2) return nums[0] < nums[1] ? 0 : 1;
    if(nums[0] < nums[numsSize - 1]) {
        return 0;
    }
    int left = 0;
    int right = numsSize - 1;
    while(left <= right) {
        int mid = left + ((right - left) >> 1);
        if(nums[mid] < nums[mid - 1]) {
            return mid;
        } else if(mid + 1 < numsSize && nums[mid] > nums[mid + 1]) {
            return mid + 1;
        }
        if(nums[mid] > nums[0]) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return -1;
}

int search(int* nums, int numsSize, int target){
    if(!numsSize) return -1;
    if(numsSize == 1) return nums[0] == target ? 0 : -1;
    //if(numsSize == 2) return target == nums[0] ? 0 : (target == nums[1] ? 1 : -1);
    int n = findMin(nums, numsSize);
    // printf("%d", n);
    if(nums[n] == target) return n;
    int left = 0;
    int right = 0;
    if(target > nums[0]) {
        left = 0;
        right = n == 0 ? numsSize - 1 :n - 1;
    } else if(nums[0] == target) {
        return 0;
    } else {
        if(n == 0) return -1;
        left = n;
        right = numsSize - 1;
    }

    while(1) {
        int mid = (right + left) >> 1;
        if(nums[mid] == target) {
            return mid;
        } else if(target > nums[mid]) {
            left = mid;
        } else {
            right = mid;
        }
        if(left + 1 >= right) break;
    }
    if(nums[left] == target) return left;
    if(nums[right] == target) return right;
    return -1;
}
