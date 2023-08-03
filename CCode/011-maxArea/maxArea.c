
#include<stdio.h>
#include<stdlib.h>

int min(int a, int b){
    return a <= b ? a : b;
}

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;

    int max = 0;
    int area = 0;

    while(left < right) {
        if(height[left] >= height[right]) {
            area = height[right] * (right - left);
            right--;
        } else {
            area = height[left] * (right - left);
            left++;
        }
        if(max < area) {
            max = area;
        }
    }

    return max;
}

int main() {
    int height[] = {1,8,6,2,5,4,8,3,7};
    int len = (int)sizeof(height)/(int)sizeof(height[0]);
    printf("%d\n", maxArea(height, len));
    return 0;
}