//
// Created by shuai on 2023/8/19.
//

#include<string.h>
#include<stdlib.h>

int longestValidParentheses(char * s){
    int len = strlen(s);
    if(len < 2) return 0;
    int left = 0;
    int right = 0;
    int res = 0;
    for(int i = 0; i < len; i++) {
        if(s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if(right == left) {
            res = res >= (right << 1) ? res : (right << 1);
        }
        if(right > left) {
            left = 0;
            right = 0;
        }
    }
    left = 0;
    right = 0;
    for(int i = len - 1; i >= 0; i--) {
        if(s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if(right == left) {
            res = res >= (left << 1) ? res : (left << 1);
        }
        if(right < left) {
            left = 0;
            right = 0;
        }
    }
    return res;

}

int longestValidParenthesesOlder(char * s){
    int len = strlen(s);
    if(len < 2) return 0;
    int* dp = (int*)malloc(sizeof(int) * len);
    dp[0] = 0;
    int res = 0;
    for(int i = 1; i < len; i++) {
        if(s[i] == '(') {
            dp[i] = 0;
        } else {
            if(s[i - 1] == '(') {
                if(i > 1) {
                    dp[i] = dp[i - 2] + 2;
                } else {
                    dp[i] = 2;
                }
            } else {
                int p = i - 1 - dp[i - 1];
                if(p < 0) {
                    dp[i] = 0;
                    continue;
                }
                dp[i] = s[i - 1 - dp[i - 1]] == '(' ? dp[i - 1] + 2 : 0;
                if(dp[i] && p - 1 >= 0 && s[p - 1] == ')' && dp[i - 1] ) dp[i] += dp[p - 1];
            }
        }
        res = dp[i] > res ? dp[i] : res;

    }
    return res;

}