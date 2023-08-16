package com.leetcode.achStrStr;

class Solution {
    private static int[] getNext(char[] str) {
        int len = str.length;
        int[] next = new int[len];
        if(len == 0) return next;
        next[0] = -1;
        if(len == 1) return next;
        next[1] = 0;
        if(len == 2) return next;
        int i = 2;
        int j = 0;
        while(i < len) {
            if(str[i - 1] == str[j]) {
                next[i++] = ++j;
            } else if(next[j] == -1) {
                next[i++] = j;
            } else {
                j = next[j];
            }
        }
        return next;
    }
    public int strStr(String haystack, String needle) {
        int l1 = haystack.length();
        int l2 = needle.length();
        if(l2 > l1) return -1;
        char[] str1 = haystack.toCharArray();
        char[] str2 = needle.toCharArray();
        int[] next = getNext(str2);
        int i1 = 0;
        int i2 = 0;
        while(i1 < l1 && i2 < l2) {
            if(str1[i1] == str2[i2]) {
                i1++;
                i2++;
            } else if(next[i2] == -1) {
                i1++;
            } else {
                i2 = next[i2];
            }
        }
        return i2 == l2 ? i1 - i2 : -1;
    }
}
