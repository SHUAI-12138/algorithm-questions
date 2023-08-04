package com.leetcode.abdLongestCommonPrefix;

public class Solution {

    public String longestCommonPreifx(String[] strs) {
        int pos = 0;
        boolean flag = false;
        int len = strs.length;

        while(true) {
            if(pos == strs[0].length()) break;
            char ch = strs[0].charAt(pos);
            for (int i = 0; i < strs.length; i++) {
                if (strs[i].charAt(pos) != ch || pos == strs[i].length()) {
                    flag = true;
                    break;
                }
            }

            if(flag) {
                break;
            }
            pos++;
        }

        if(pos == 0) return "";
        return strs[0].substring(0,pos);
    }
}
