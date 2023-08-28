package com.leetcode.aedIsMatch;


class Solution {
    public boolean isMatch(String s, String p) {
        int lens = s.length();
        int lenp = p.length();
        int i = 0, j = 0;
        int sStar = -1, pStar = -1;
        while(i < lens) {
            if(j < lenp && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '?')) {
                ++i;
                ++j;
            }  else if(j < lenp && p.charAt(j) == '*'){
                sStar = i;
                pStar = j++;
            } else if(sStar >= 0) {
                i = ++sStar;
                j = pStar + 1;
            } else return false;
        }
        if(i != lens) return false;
        while(j < lenp && p.charAt(j) == '*') ++j;
        return j == lenp;
    }
}


//  动态规划
class SolutionByDP {
    public boolean isMatch(String s, String p) {
        int lens = s.length();
        int lenp = p.length();
        boolean[][] dp = new boolean[lens + 1][lenp + 1];

        // 初始化二维动态数组
        // dp[0][0] = 0
        // dp[i][0] = false, i != 0 (s不为空， p为空， 匹配不上)
        // dp[0][j] = false, p[j] != '*' (如果p为连续的'*'，则为true，直至不为'*'的位置)
        for(int j = 1; j <= lenp; j++) {
            if(p.charAt(j - 1) != '*') break;
            dp[0][j] = true;
        }
        dp[0][0] = true;

        for(int i = 1; i <= lens; i++) {
            for(int j = 1; j <= lenp; j++) {
                if(s.charAt(i - 1) == p.charAt(j - 1) || p.charAt(j - 1) == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    if(p.charAt(j - 1) == '*') {
                        dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                    }
                }
            }
        }
        return dp[lens][lenp];
    }
}
