package com.leetcode.aeiRotate;

class Solution {
    public void rotate(int[][] matrix) {
        int L = 0;
        int R = matrix.length - 1;
        while(L < R) {
            for(int i = 0; L + i < R; i++) {
                int tmp = matrix[L][L + i];
                matrix[L][L + i] = matrix[R - i][L];
                matrix[R - i][L] = matrix[R][R - i];
                matrix[R][R - i] = matrix[L + i][R];
                matrix[L + i][R] = tmp;
            }
            ++L;
            --R;
        }
    }
}
