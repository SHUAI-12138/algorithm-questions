
#include<stdlib.h>
#include<stdio.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** generateParenthesis(int n, int* returnSize){
    char** result = (char**)malloc(sizeof(char*) * 1430);
    char* res = (char*)malloc(sizeof(char) * (( n << 1) | 1));
    *returnSize = 0;
    backTracking(0, 0, n, returnSize, result, res);
    return result;
}

void backTracking(int left, int right, int n, int* returnSize, char** result, int* res) {
    if(right == n && left == right) {
        result[*returnSize] = (char*)malloc(((n << 1) | 1) * sizeof(char));
        if(result[*returnSize]) {
            for(int i = 0; i < (n << 1); i++) {
                result[*returnSize][i] = res[i];
            }
            result[(*returnSize)++][n << 1] = '\0';
        }
        return;
    }
    if(left < n) {
        res[left + right] = '(';
        backTracking(left + 1, right, n, returnSize, result, res);
    }
    if(right < left) {
        res[left + right] = ')';
        backTracking(left, right + 1, n, returnSize, result, res);
    }
}




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void Backtracking1(int left, int right, int n, char* str, int index, char** result, int* returnSize) {
	if (right == n) {
		result[*returnSize] = (char*)malloc(sizeof(char) * (2 * n + 1));
		if (result[*returnSize]) {
			for (int i = 0; i < 2 * n; i++)
				result[*returnSize][i] = str[i];
			result[(*returnSize)++][2 * n] = '\0';
		}
		return ;
	}
	if (left < n) {
		str[index] = '(';
		Backtracking(left + 1, right, n, str, index + 1, result, returnSize);
	}
	if (right < left && right < n) {
		str[index] = ')';
		Backtracking(left, right + 1, n, str, index + 1, result, returnSize);
	}
}

char** generateParenthesis1(int n, int* returnSize) {
	char* str = (char*)malloc((2 * n + 1) * sizeof(char));
	char** result = (char**)malloc(sizeof(char*) * 1430);
	*returnSize = 0;
	Backtracking(0, 0, n, str, 0, result, returnSize);

	return result;
}