
#include<stdio.h>
#include<stdlib.h>

int cmp_int(const void* e1, const void* e2){
    return *(int*)e1-*(int*)e2;
}

int threeSumClosest(int* nums, int numsSize, int target){
    int ret = 100000, k = 0, i = 0, j = 0, sum = 0;
	qsort(nums, numsSize, sizeof(nums[0]), cmp_int);
    if (nums[0] + nums[1] + nums[2] >= target)
		return nums[0] + nums[1] + nums[2];
	if (nums[numsSize - 1] + nums[numsSize - 2] + nums[numsSize - 3] <= target)
		return nums[numsSize - 1] + nums[numsSize - 2] + nums[numsSize - 3];
	for (k = 0; k < numsSize - 2; k++) {
		i = k + 1, j = numsSize - 1;
		while (i < j) {
			sum = nums[k] + nums[i] + nums[j];
			ret = (abs(ret - target) <= abs(sum - target)) ? ret : sum;
			if (sum > target)
				j--;
			else if (sum < target)
				i++;
			else
				return target;
		}
	}
	return ret;
}