package com.leetcode.aaeLongestPalindrome;

public class Solution {
    public static void main(String[] args) {
        String s = "babad";
        Solution solution = new Solution();
        System.out.println(solution.longestPalindrome(s));
    }

    public String longestPalindrome(String s) {

        int strLen = s.length();
        if(strLen < 2) {
            return s;
        }

        int pre = 1;
        int left = 0, right = 0;
        int pos = 0, length = 0;

        while(pre < strLen) {
            left = pre - 1;
            right = pre;
            if(s.charAt(left) == s.charAt(right)) {
                int tmp = 2;
                left--;
                right++;
                while(left >= 0 && right < strLen && s.charAt(left) == s.charAt(right)) {
                    tmp += 2;
                    left--;
                    right++;
                }
                if(length < tmp) {
                    length = tmp;
                    pos = left + 1;
                }
            }
            left = pre - 1;
            right = pre;
            if(++right < strLen && s.charAt(right) == s.charAt(left)) {
                int tmp = 3;
                left--;
                right++;
                while(left >= 0 && right < strLen && s.charAt(left) == s.charAt(right)) {
                    tmp += 2;
                    left--;
                    right++;
                }
                if(length < tmp) {
                    length = tmp;
                    pos = left + 1;
                }
            }
            if(length == strLen) return s;
            pre++;
        }
        if(length == 0) {
            String ret = new String();
            ret = s.substring(0, 1);
            return ret;
        }
        String ret = new String();
        ret = s.substring(pos, pos + length);

        return ret;
    }
}
