//
// Created by shuai on 2023/8/26.
//
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

char * multiply(char * num1, char * num2){
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1 + len2 - 1;
    int result[len];
    char* res = (char*)malloc(sizeof(char) * (len + 8));
    memset(result, 0, sizeof(result));
    for(int i = 0; i < len1; i++) {
        for(int j = 0; j < len2; j++) {
            result[i + j] += (int)(num1[i] - '0') * (int)(num2[j] - '0');
        }
    }
    int carry = 0;
    for(int i = len - 1; i > 0; i--) {
        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }
    result[0] += carry;
    sprintf(res, "%d", result[0]);
    if(result[0] == 0) return res;
    for(int i = 1; i < len; i++) {
        sprintf(res + strlen(res), "%d", result[i]);
    }
    return res;
}