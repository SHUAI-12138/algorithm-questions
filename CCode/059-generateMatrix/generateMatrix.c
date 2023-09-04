//
// Created by shuai on 2023/9/4.
//
#include<stdlib.h>


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int** ans = (int**)malloc(sizeof(int*) * n);
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        ans[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    *returnSize = n;
    int flag = 1;
    int N = n * n;
    int x = 0, y = -1;
    for(int i = 1; i <= N; i++) {
        switch (flag % 4) {
            case 1 :
                ans[x][++y] = i;
                if (y == n - flag / 4 - 1) flag++;
                break;
            case 2 :
                ans[++x][y] = i;
                if (x == n - flag / 4 - 1) flag++;
                break;
            case 3 :
                ans[x][--y] = i;
                if (y == flag / 4) flag++;
                break;
            case 0 :
                ans[--x][y] = i;
                if (x == flag / 4) flag++;
        }
    }
    return ans;
}
