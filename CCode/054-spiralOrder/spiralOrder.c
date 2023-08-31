//
// Created by shuai on 2023/8/31.
//

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int R = matrixSize, C = *matrixColSize;
    int len = R * C;
    int* res = (int*)malloc(sizeof(int) * len);
    (*returnSize) = len;
    int flag = 1;
    int row = 0, col = -1;
    for(int i = 0; i < len; i++) {

        switch(flag % 4) {
            case 1:
                col++;
                if(col == C - 1 - flag / 4) flag++;
                break;
            case 2:
                row++;
                if(row == R - 1 - flag / 4) flag++;
                break;
            case 3:
                col--;
                if(col == flag / 4) flag++;
                break;
            case 0:
                row--;
                if(row == flag / 4) flag++;
                break;
        }
        res[i] = matrix[row][col];
    }
    return res;
}
