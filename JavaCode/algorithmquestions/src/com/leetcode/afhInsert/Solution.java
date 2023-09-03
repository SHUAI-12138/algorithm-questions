package com.leetcode.afhInsert;

import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> ans = new ArrayList<>();
        if(intervals.length == 0) return new int[][]{newInterval};
        int L = newInterval[0];
        int R = newInterval[1];
        boolean flag = true;
        for(var interval : intervals) {
            if(R < interval[0]) {
                if(flag) {
                    ans.add(new int[]{L, R});
                    flag = false;
                }
                ans.add(interval);
            } else if(L > interval[1]) {
                ans.add(interval);
            } else {
                L = Math.min(L, interval[0]);
                R = Math.max(R, interval[1]);
            }
        }
        if(flag) {
            ans.add(new int[]{L, R});
        }
        return ans.toArray(new int[ans.size()][2]);
    }
}
