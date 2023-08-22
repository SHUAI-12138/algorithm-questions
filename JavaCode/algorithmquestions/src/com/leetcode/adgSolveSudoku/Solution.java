package com.leetcode.adgSolveSudoku;

class Solution {
    public static boolean flag = false;

    public static void backstracking(char[][] board, int[] row, int[] col, int block[], int pos) {
        if(pos == 81) {
            flag = true;
            return;
        }
        int R = pos / 9;
        int C = pos % 9;
        if(board[R][C] != '.') {
            backstracking(board, row, col, block, pos + 1);
            return;
        }
        int B = (C / 3) * 3 + R / 3;
        int choice = ((row[R] | col[C] | block[B]) ^ 511); // 511(10) = 1_1111_1111(2)
        if(choice == 0) return;
        for(int i = 0; choice > 0; i++) {
            if(choice % 2 == 1) {
                int ans = (1 << i);
                row[R] ^= ans;
                col[C] ^= ans;
                block[B] ^= ans;
                board[R][C] = (char)(i + '1');
                //System.out.println(pos + ": " + board[R][C]);
                backstracking(board, row, col, block, pos + 1);
                //System.out.println(flag);
                if(flag) return;
                row[R] ^= ans;
                col[C] ^= ans;
                block[B] ^= ans;
                board[R][C] = '.';
            }
            choice >>= 1;
        }

    }

    public void solveSudoku(char[][] board) {
        flag = false;
        int[] row = new int[9];
        int[] col = new int[9];
        int[] block = new int[9];
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                int tmp = ((1 << (int)(board[i][j] - '0')) >> 1);
                int pos = (j / 3) * 3 + i / 3;
                row[i] |= tmp;
                col[j] |= tmp;
                block[pos] |= tmp;
            }
        }
        backstracking(board, row, col, block, 0);
    }
}
