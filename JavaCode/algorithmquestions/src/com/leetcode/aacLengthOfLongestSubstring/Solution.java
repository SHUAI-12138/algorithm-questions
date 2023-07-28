package com.leetcode.aacLengthOfLongestSubstring;

import java.util.HashMap;
import java.lang.Character;

public class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.lengthOfLongestSubstring1("abcabcbb"));
        System.out.println(solution.lengthOfLongestSubstring("abcabcbb"));
    }

    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();

        int head = 0;
        int num = 0;
        int longest = 0;

        for (int i = 0; i < s.length(); i++) {
            if (map.get(s.charAt(i)) != null) {
                int tmp = map.get(s.charAt(i));
                for (int j = tmp; j >= head; j--) {
                    map.remove(s.charAt(j));
                    num--;
                }
                head = tmp + 1;
            }
            map.put(s.charAt(i), i);
            num++;
            longest = longest < num ? num : longest;
        }

        return longest;
    }

    public int lengthOfLongestSubstring1(String s) {
        int[] m_map = new int[128];
        for (int i = 0; i < 128; i++) {
            m_map[i] = -1;
        }

        int head = 0;
        int num = 0;
        int longest = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            if (m_map[ch] != -1) {
                int tmp = m_map[ch];
                for (int j = tmp; j >= head; j--) {
                    m_map[s.charAt(j)] = -1;
                    num--;
                }
                head = tmp + 1;
            }

            m_map[s.charAt(i)] = i;
            num++;
            longest = longest >= num ? longest : num;
        }
        return longest;
    }
}
