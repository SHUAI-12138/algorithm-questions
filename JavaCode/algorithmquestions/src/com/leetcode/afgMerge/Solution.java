package com.leetcode.afgMerge;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

class Solution {
    public int[][] merge(int[][] intervals) {
        List<int[]> ans = new ArrayList<>();
        Arrays.sort(intervals, new Comparator<int[]>(){
            public int compare(int[] e1, int[] e2) {
                return e1[0] - e2[0];
            }
        });
        int L = intervals[0][0];
        int R = intervals[0][1];
        for(int i = 0; i < intervals.length; i++) {
            if(intervals[i][0] <= R) {
                if(intervals[i][1] > R) R = intervals[i][1];
            } else {
                ans.add(new int[]{L, R});
                L = intervals[i][0];
                R = intervals[i][1];
            }
        }
        ans.add(new int[]{L, R});
        return ans.toArray(new int[ans.size()][2]);
    }
}
