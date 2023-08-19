package com.leetcode.adbLongestValidParentheses;

class Solution {
    public int longestValidParentheses(String s) {
        int len = s.length();
        if(len < 2) return 0;
        int left = 0;
        int right = 0;
        int res = 0;
        for(int i = 0; i < len; i++) {
            if(s.charAt(i) == '(') left++;
            if(s.charAt(i) == ')') right++;
            if(left == right) res = Math.max(res, 2 * right);
            if(right > left) {
                right = 0;
                left = 0;
            }
        }
        left = 0;
        right = 0;
        for(int i = len - 1; i >= 0; i--) {
            if(s.charAt(i) == '(') left++;
            if(s.charAt(i) == ')') right++;
            if(left == right) res = Math.max(res, 2 * left);
            if(right < left) {
                right = 0;
                left = 0;
            }
        }
        return res;
    }
}