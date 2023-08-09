package com.leetcode.abgLetterCombinations;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        if(digits.isEmpty()) return result;
        int depth = digits.length();
        if(depth == 0) {
            return result;
        }

        HashMap<Character, String> phoneMap = new HashMap<Character, String>() {{
            put('2', "abc");
            put('3', "def");
            put('4', "ghi");
            put('5', "jkl");
            put('6', "mno");
            put('7', "pqrs");
            put('8', "tuv");
            put('9', "wxyz");
        }};
        char[] res = new char[depth];
        backTracking(digits, phoneMap, 0, depth, result, res);
        return result;
    }

    public static void backTracking(String digits, HashMap<Character, String> phoneMap, int index, int depth, List<String> result, char[] res) {
        if(index == depth) {
            String temp = new String(res);
            result.add(temp);
            return;
        }
        String digit = phoneMap.get(digits.charAt(index));
        int len = digit.length();
        for(int i = 0; i < len; i++) {
            res[index] = digit.charAt(i);
            backTracking(digits, phoneMap, index + 1, depth, result, res);
        }
    }

}
