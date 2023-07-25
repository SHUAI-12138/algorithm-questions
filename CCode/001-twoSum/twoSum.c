#include<stdio.h>
#include<stdlib.h>

typedef struct hash {
	int site;
	struct hash* next;
}hash;

void add_map(hash* map[], int val, int p, int site) {
	hash* node = (hash*)malloc(sizeof(hash));
	node->site = site;
	node->next = NULL;
	int place = val % p;
    if (place < 0)
		place = -place;
	if (map[place] == NULL) {
		map[place] = node;
		return;
	}
	hash* index = map[place];
	while (index->next != NULL) {
		index = index->next;
	}
	index->next = node;
}

int find_map(hash* map[], int* nums, int key, int p, int site) {
	int place = key % p;
    if (place < 0)
		place = -place;
	hash* index = map[place];
	if (index == NULL) {
		return -1;
	}
	while (index) {
		if (nums[index->site] == key && index->site != site) {
			return index->site;
		}
		index = index->next;
	}
	return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int p = numsSize;
	hash** map = (hash**)malloc(sizeof(hash*) * p);
	for (int i = 0; i < p; i++) {
		map[i] = NULL;
	}
	for (int i = 0; i < numsSize; i++) {
		add_map(map, nums[i], p, i);
	}
	for (int i = 0; i < numsSize; i++) {
		int temp = target - nums[i];
		int j = find_map(map, nums, temp, p, i);
		if (j != -1) {
			int* ret = (int*)malloc(sizeof(int) * 2);
			ret[0] = i <= j ? i : j;
			ret[1] = i <= j ? j : i;
			*returnSize = 2;
			return ret;
		}
	}
	*returnSize = 0;
	return NULL;
}

int main(){
    int nums1[4] = {2, 7, 11, 15};
    int numsSize = (int)(sizeof(nums1) / sizeof(nums1[0]));
    int* result = NULL;
    int returnSize = 0;
    result = twoSum(nums1, numsSize, 9, &returnSize);
    printf("[%d, %d]", result[0], result[1]);
    return 0;
}