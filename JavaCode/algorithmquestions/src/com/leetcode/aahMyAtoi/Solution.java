package com.leetcode.aahMyAtoi;

public class Solution {
    public static void main(String[] args) {
        System.out.println(Solution.myAtoi("42"));
    }

    public static int myAtoi(String s) {
        int num = 0;
        int flag = 0;
        int p = 0;
        int len = s.length();

        while(p < len) {
            while(s.charAt(p) == ' ') {
                if(p + 1 >= len) return 0;
                p++;
            }
            if(flag == 0) {
                if(s.charAt(p) == '+') {
                    flag = 1;
                    p++;
                } else if (s.charAt(p) == '-') {
                    flag = -1;
                    p++;
                } else if (s.charAt(p) >= '0' && s.charAt(p) <= '9') {
                    flag = 1;
                }
            }

            if(p >= len || s.charAt(p) < '0' || s.charAt(p) > '9') {
                break;
            }

            int tmp = s.charAt(p) - '0';
            if(num > 0x7fffffff / 10 || (num == 0x7fffffff / 10 && tmp > 7)) {
                return flag == 1 ? 0x7fffffff : 0x80000000;
            }
            num = num * 10 + tmp;
            if(p + 1 <len && s.charAt(p + 1) >= '0' && s.charAt(p) <= '9') {
                p++;
            } else {
                break;
            }

        }



        return num * flag;
    }

}
