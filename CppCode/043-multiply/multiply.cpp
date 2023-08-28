//
// Created by shuai on 2023/8/26.
//
#include<string>
#include<vector>
#include<stdio.h>
#include<string.h>

using namespace std;

// 字符串相乘
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int len = len1 + len2 - 1;
        char* res = (char*)malloc(sizeof(char) * (len + 8));
        vector<int> result(len, 0);
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
};