package com.leetcode.afiLengthOfLastWord;

class Solution {
    public int lengthOfLastWord(String s) {
        int end = s.length();
        int start = end;
        while(s.charAt(--start) == ' ');
        end = start;
        while(start > 0 && s.charAt(--start) != ' ');
        return end - start + ((start == 0 && s.charAt(start) != ' ') ? 1 : 0);
    }
}
