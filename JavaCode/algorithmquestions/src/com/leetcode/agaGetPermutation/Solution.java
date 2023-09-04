package com.leetcode.agaGetPermutation;


import java.util.LinkedList;

class Solution {
    public String getPermutation(int n, int k) {
        LinkedList<Integer> help = new LinkedList<>();
        LinkedList<Integer> ans = new LinkedList<>();
        char[] ch = new char[n];
        for(int i = 0; i < n;) {
            help.add(++i);
        }
        int nF = 1;
        for(int i = 2; i < n; i++) {
            nF *= i;
        }
        for(int i = n - 1; i > 2; i--) {
            if(nF <= k) break;
            ans.add(help.removeFirst());
            nF /= i;
            n--;
        }

        while(n > 2 && k != 0) {
            int index = k / nF + (k % nF == 0 ? 0 : 1);
            ans.add(help.remove(index - 1));
            k -= (k / nF) * nF;
            if(k == 0) break;
            n--;
            nF /= n;
        }

        if(k == 0 || k > 1) {
            while(help.size() != 0) {
                ans.add(help.removeLast());
            }
        } else {
            while(help.size() != 0) {
                ans.add(help.removeFirst());
            }
        }

        for(int i = 0; i < ans.size(); i++) {
            ch[i] = (char)(ans.get(i) ^ 0x30);
        }
        return new String(ch);
    }
}