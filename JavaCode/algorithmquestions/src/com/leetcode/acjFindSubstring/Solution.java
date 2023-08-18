package com.leetcode.acjFindSubstring;

import java.util.*;

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        int len = s.length();
        int wordSize = words[0].length();
        int wordNum = words.length;
        List<Integer> res = new ArrayList<>();
        if(len < wordNum * wordSize) return res;
        HashMap<String, Integer> target = new HashMap<String, Integer>();
        for (String word : words) {
            target.put(word, target.getOrDefault(word, 0) + 1);
        }
        for(int i = 0; i < wordSize; i++) {
            HashMap<String, Integer> map = new HashMap<>();
            int left = i;
            int right = i;
            int count = 0;
            while(right + wordSize <= len) {
                String str = s.substring(right, right + wordSize);
                if(target.containsKey(str)) {
                    map.put(str, map.getOrDefault(str, 0) + 1);
                    right += wordSize;
                    count++;

                    while (map.get(str) > target.get(str)) {
                        String temp = s.substring(left, left + wordSize);
                        map.put(temp, map.get(temp) - 1);
                        left += wordSize;
                        count--;
                    }

                    if (count == wordNum) {
                        res.add(left);
                    }
                } else {
                    map.clear();
                    count = 0;
                    left = right;
                }

            }
        }
        return res;
    }
}