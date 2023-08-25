//
// Created by shuai on 2023/8/25.
//
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a >= b ? a : b;
}

// 动态规划 运行时间 8 ms
int trap(int* height, int heightSize){
    if(heightSize < 2) return 0;
    int leftMax[heightSize];
    memset(leftMax, 0, sizeof(leftMax));
    leftMax[0] = height[0];
    for(int i = 1; i < heightSize; i++) {
        leftMax[i] = max(height[i], leftMax[i - 1]);
    }

    int rightMax[heightSize];
    memset(rightMax, 0, sizeof(rightMax));
    rightMax[heightSize - 1] = height[heightSize - 1];
    for(int i = heightSize - 2; i >= 0; i--) {
        rightMax[i] = max(height[i], rightMax[i + 1]);
    }
    int res = 0;
    for(int i = 0; i < heightSize; i++) {
        res += min(leftMax[i], rightMax[i]) - height[i];
    }
    return res;
}