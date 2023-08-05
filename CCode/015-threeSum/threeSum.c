
#include<stdio.h>
#include<stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp_int(const int* e1, const int* e2){
    return *(int*)e1-*(int*)e2;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
	if (numsSize < 3) {
		return NULL;
	}
	qsort(nums, numsSize, sizeof(int), cmp_int);
	int** ret = (int**)malloc(sizeof(int*) * numsSize * numsSize);
	*returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize);
	int i = 0, j = 0, k = 0, sum = 0;
	if (ret && *returnColumnSizes) {
		for (k = 0; k < numsSize - 2; k++) {
			if (nums[k] > 0) {
				return ret;
			}
			if (k > 0 && nums[k] == nums[k - 1]) {
				continue;
			}
			i = k + 1;
			j = numsSize - 1;
			while (i < j) {
				sum = nums[k] + nums[i] + nums[j];
				if (sum == 0) {
					(*returnColumnSizes)[*returnSize] = 3;
					ret[*returnSize] = (int*)malloc(sizeof(int) * 3);
					if (ret) {
						ret[*returnSize][0] = nums[k];
						ret[*returnSize][1] = nums[i];
						ret[*returnSize][2] = nums[j];
					}
					(*returnSize)++;
					while (i < j && nums[i] == nums[++i]);
					while (i < j && nums[j] == nums[--j]);
				}
				else if (sum > 0)
					j--;
				else
					i++;
			}
		}
	}
	return ret;
}