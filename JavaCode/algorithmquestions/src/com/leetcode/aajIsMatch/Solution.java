package com.leetcode.aajIsMatch;

public class Solution {

    public static void main(String[] args) {
        System.out.println(Solution.isMatch("aa", "a*"));
    }

    // 动态规划
    public static boolean isMatch(String s, String p) {
        int len_s = s.length();
        int len_p = p.length();

        // 默认值为false,所以当p为空，s不为空，dp[][]值为false不需要初始化
        // 也就是dp[i][0]默认为false
        boolean[][] dp = new boolean[len_s + 1][len_p + 1];

        // 初始化

        // s为空，p为空时，能够匹配上
        dp[0][0] = true;

        // 当s为空时，如果p[j] != '*' ，则dp[0][j] = false
        // 当s为空且p[j] == '*' 时， dp[0][j] = dp[0][j - 2]
        // 例如: "ab*" dp[0][3] = dp[0][1] = false
        // 例如: "a*"  dp[0][2] = dp[0][0] = true
        // '*' 最早出现的位置下标为1， 此时j == 2，所以不用考虑越界问题
        for(int j = 1; j <= len_p; j++) {
            if(p.charAt(j - 1) == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for(int i = 1; i <= len_s; i++) {
            for(int j = 1; j <= len_p; j++) {
                if(s.charAt(i - 1) == p.charAt(j - 1) || p.charAt(j - 1) == '.'){
                    dp[i][j] = dp[i - 1][j - 1];
                } else if(p.charAt(j - 1) == '*') {
                    if(s.charAt(i - 1) != p.charAt(j - 2) && p.charAt(j - 2) != '.') {
                        dp[i][j] = dp[i][j - 2];
                    } else {
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                    }
                    // 上面代码与该行代码等价
                    // dp[i][j] = dp[i][j - 2] || ((s.charAt(i - 1) == p.charAt(j - 2) || p.charAt(j - 2) == '.') && dp[i - 1][j]);
                }

            }
        }

        return dp[len_s][len_p];
    }





}
