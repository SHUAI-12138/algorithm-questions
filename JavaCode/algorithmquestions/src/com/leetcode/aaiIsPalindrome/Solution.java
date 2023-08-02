package com.leetcode.aaiIsPalindrome;

public class Solution {
    public static void main(String[] args) {
        System.out.println(Solution.isPalindrome(12321));
    }
    public static boolean isPalindrome(int x) {
        if(x < 0 || x % 10 == 0) return false;
        int oldNum = x;
        int newNum = 0;
        while(oldNum > 0) {
            newNum = newNum * 10 + oldNum % 10;
            oldNum /= 10;
        }
        return newNum == x ? true : false;
    }
}
