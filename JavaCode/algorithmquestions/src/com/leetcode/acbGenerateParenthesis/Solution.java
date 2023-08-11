package com.leetcode.acbGenerateParenthesis;

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        char[] res = new char[n << 1];
        backTracking(0, 0, n, result, res);
        return result;
    }

    public static void backTracking(int left, int right, int n, List<String> result, char[] res) {
        if(right == n) {
            String tmp = new String(res);
            result.add(tmp);
        }
        if(left < n) {
            res[left + right] = '(';
            backTracking(left + 1, right, n, result, res);
        }
        if(right < left) {
            res[left + right] = ')';
            backTracking(left, right + 1, n, result, res);
        }
    }
}
