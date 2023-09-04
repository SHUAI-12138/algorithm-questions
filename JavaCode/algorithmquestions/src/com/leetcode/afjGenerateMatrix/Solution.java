package com.leetcode.afjGenerateMatrix;

import java.util.Arrays;

class Solution {
    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];
        int flag = 1;
        int N = n * n;
        int x = 0, y = -1;
        for(int i = 1; i <= N; i++) {
            switch (flag % 4) {
                case 1 -> {
                    ans[x][++y] = i;
                    if (y == n - flag / 4 - 1) flag++;
                }
                case 2 -> {
                    ans[++x][y] = i;
                    if (x == n - flag / 4 - 1) flag++;
                }
                case 3 -> {
                    ans[x][--y] = i;
                    if (y == flag / 4) flag++;
                }
                case 0 -> {
                    ans[--x][y] = i;
                    if (x == flag / 4) flag++;
                }
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] arr = solution.generateMatrix(3);
        for(int[] a : arr) {
            System.out.println(Arrays.toString(a));
        }
    }
}