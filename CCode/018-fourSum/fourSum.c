
#include<stdlib.h>
#include<stdio.h>


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp_int(const int* e1, const int* e2) {
	return *(int*)e1 - *(int*)e2;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
	int** ret = NULL;
	*returnSize = 0;
	if (numsSize < 4)
		return ret;
	qsort(nums, numsSize, sizeof(int), cmp_int);
	ret = (int**)malloc(sizeof(int*) * numsSize * numsSize * numsSize);
	*returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize * numsSize);
	int a = 0, b = 0, c = 0, d = 0;
    long sum = 0;
	for (; a < numsSize - 3; a++) {
		if (nums[a] + nums[a + 1] > (long)target - nums[a + 2] - nums[a + 3])
			return ret;
		if (a > 0 && nums[a] == nums[a - 1])
			continue;
		if (nums[a] + nums[numsSize - 1] < (long)target - nums[numsSize - 2] - nums[numsSize - 3])
			continue;
		for (b = a + 1; b < numsSize - 2; b++) {
			if (b > a + 1 && nums[b] == nums[b - 1])
				continue;
			if (nums[a] + nums[b]  < (long)target - nums[numsSize - 1] - nums[numsSize - 2])
				continue;
			if (nums[a] + nums[b] > (long)target - nums[b + 1] - nums[b + 2])
				break;
			c = b + 1;
			d = numsSize - 1;
			while (c < d) {
				sum = (long)nums[a] + nums[b] + nums[c] + nums[d];
				if (sum == target) {
					int* tmp = (int*)malloc(sizeof(int) * 4);
					(*returnColumnSizes)[*returnSize] = 4;
					if (tmp) {
						tmp[0] = nums[a];
						tmp[1] = nums[b];
						tmp[2] = nums[c];
						tmp[3] = nums[d];
					}
					ret[(*returnSize)++] = tmp;
					c++;
					d--;
					while (c < d && nums[c] == nums[c - 1])
						c++;
					while (c < d && nums[d] == nums[d + 1])
						d--;
				}
				else if (sum < target)
					c++;
				else
					d--;
			}
		}
	}
	return ret;
}