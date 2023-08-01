package com.leetcode.aafConvert;

public class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "PAYPALISHIRING";
        System.out.println("PAHNAPLSIIGYIR\tPINALSIGYAHRPI\t(answer)");
        String str1 = solution.convert(s, 3);
        String str2 = solution.convert(s, 4);
        System.out.println(str1 + "\t" + str2);
        str1 = solution.convertOptimize(s, 3);
        str2 = solution.convertOptimize(s, 4);
        System.out.println(str1 + "\t" + str2);
    }

    public String convert(String s, int numRows) {
        int len = s.length();
        if(len <= numRows || numRows == 1) {
            return s;
        }
        String ret = new String();
        int turn = (numRows << 1) - 2;

        for(int row = 0; row < numRows; row++) {
            for(int i = 0; i * turn + row < len; i++) {
                int cur = i * turn + row;
                ret += s.substring(cur, cur + 1);
                if(row != 0 && row != numRows - 1) {
                    cur = (i + 1) * turn - row;
                    if(cur < len) {
                        ret += s.substring(cur, cur + 1);
                    } else {
                        break;
                    }
                }
            }
        }
        return ret;
    }

    public String convertOptimize(String s, int numRows) {
        int len = s.length();
        if(len <= numRows || numRows ==1) {
            return s;
        }
        char[] ch = new char[len];
        // 不用最后一位加 '\0' 加了反而有问题
        // 初始化给String之后，输出是会输出nul 或 '\u0000'
        // char ch[] = new char[len + 1];
        // ch[len] = '\0';

        int turn = (numRows << 1) - 2;
        int cur = 0;

        for(int row = 0; row < numRows; row++) {
            for(int i = 0;i * turn + row < len; i++) {
                int dex = i * turn + row;
                ch[cur++] = s.charAt(dex);
                if(row != 0 && row != numRows - 1) {
                    dex = dex + turn - (row << 1);
                    if(dex < len) {
                        ch[cur++] = s.charAt(dex);
                    } else {
                        break;
                    }
                }
            }
        }

        String ret = new String(ch);
        return ret;
    }
}
