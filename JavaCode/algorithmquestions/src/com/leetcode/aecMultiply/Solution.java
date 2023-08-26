package com.leetcode.aecMultiply;

class Solution {
    public String multiply(String num1, String num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        int len = len1 + len2 - 1;
        int[] result = new int[len];
        for(int i = 0; i < len1; i++) {
            for(int j = 0; j < len2; j++) {
                result[i + j] += (int)(num1.charAt(i) - '0') * (int)(num2.charAt(j) - '0');
            }
        }
        int carry = 0;
        for(int i = len - 1; i > 0; --i) {
            result[i] += carry;
            carry = result[i] / 10;
            result[i] %= 10;
        }
        result[0] += carry;
        StringBuffer res = new StringBuffer(Integer.toString(result[0]));
        if(result[0] == 0) return res.toString();
        for(int i = 1; i < len; i++) {
            res.append(Integer.toString(result[i]));
        }
        return res.toString();
    }
}
