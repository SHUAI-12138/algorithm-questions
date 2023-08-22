package com.leetcode.adfIsValidSudoku;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        int[] row = new int[9];
        int[] col = new int[9];
        int[] block = new int[9];
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                int tmp = 1;
                tmp = (tmp << (board[i][j] - '0') >> 1);
                int pos = i / 3 + 3 * (j / 3);
                if((block[pos] & tmp) > 0 || (col[j] & tmp) > 0 || (row[i] & tmp) > 0) return false;
                row[i] |= tmp;
                col[j] |= tmp;
                block[pos] |= tmp;
            }
        }
        return true;
    }
}