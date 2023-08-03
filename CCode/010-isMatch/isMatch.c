
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isMatch(char* s, char* p) {
        // 计算字符数组的长度，用于动态申请dp二维数组
        int count = 0;
        while(s[count] != '\0') {
            count++;
        }
        int len_s = count;
        count = 0;
        while(p[count] != '\0') {
            count++;
        }
        int len_p = count;

        // 申请二维数组空间 初始化二维数组，全部置为false
        int** dp = (int**)malloc(sizeof(int*) * (len_s + 1));
        for(int i = 0; i <= len_s; i++) {
            dp[i] = (int*)malloc(sizeof(int) * (len_p + 1));
            for(int j = 0; j <= len_p; j++) {
                dp[i][j] = 0;
            }
        }
        
        // 初始化 
        // 当s为空，p为空，即dp[0][0]， 此时值为0
        dp[0][0] = 1;
        // 当s为空，p不为空时，即dp[i][0] (i != 0) ，此时，dp值为false，
        // 二维数组初始化为false，所以不用考虑该情况的初始化
        // 当s为空，p不为空时，即dp[0][j] (j != 0) , 此时，有两种情况
        // 1. p[j] != '*', dp[0][j] = false
        // 2. p[j] == '*', dp[0][j] = dp[0][j - 2]  
        // 例：p = "a*b*c", dp[0][4] = dp[0][2] = dp[0][0] = true; dp[0][5] = false; dp[0][1] = false;...
        // 因为 j 不会出现在第一个位置 即 j >= 2 ,所以 j - 2 >= 0, 不用考虑越界访问的问题
        for(int j = 1; j <= len_p; j++) {
            if(p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // 动态数组变化
        for(int i = 1; i <= len_s; i++) {
            for(int j = 1; j <= len_p; j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '.') { // 能够匹配上时，dp[i][j] = dp[i - 1][j - 1]
                    dp[i][j] = dp[i - 1][j - 1];
                } else if(p[j - 1] == '*') { // p 匹配到 '*' 号时，两种情况
                    if(s[i - 1] != p[j - 2] && p[j - 2] != '.') {
                        // '*' 前的字符与s[i - 1]不匹配，此时 '*' 的作用是消除，所以dp[i][j] = dp[i][j - 2]
                        dp[i][j] = dp[i][j - 2];
                    } else {
                        // '*' 前的字符与s[i - 1]匹配
                        // 匹配 0 次 dp[i][j] = dp[i][j - 2] 例：s = "a", p = "ab*a*" , 此时dp[1][5] = dp[1][3] = true
                        // 匹配 1 次 dp[i][j] = dp[i - 1][j - 2] 例：s = "aa", p = "ab*a*", 此时dp[2][5] = dp[1][5] = true
                        // ...
                        // 匹配 k 次 dp[i][j] = dp[i - k][j - 2]
                        // 因此 dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || ... || dp[i - k][j - 2]
                        // 又因为 dp[i - 1][j] = dp[i - 1][j - 2] || ... || dp[i - k][j - 2]
                        // 所以dp[i][j] = dp[i][j - 2] || dp[i - 1][j]
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                    }
                }
            }
        }
        

        return dp[len_s][len_p];
}

int main() {
    char* s = "aa";
    char* p = ".*";
    isMatch(s, p) == 1 ? printf("true") : printf("false");
    return 0;
}

