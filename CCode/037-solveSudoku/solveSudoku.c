//
// Created by shuai on 2023/8/22.
//
#include<stdbool.h>

static bool flag = false;

void backstracking(char** board, int* row, int* col, int* block, int pos) {
    if(pos == 81) {
        flag = true;
        return;
    }
    int R = pos / 9;
    int C = pos % 9;
    if(board[R][C] != '.') {
        backstracking(board, row, col, block, pos + 1);
        return;
    } else {
        int B = (C / 3) * 3 + R / 3;
        int choice = (row[R] | col[C] | block[B]) ^ 511;
        if(choice == 0) return;
        for(int i = 0; choice; i++) {
            if(choice % 2) {
                int ans = (1 << i);
                row[R] ^= ans;
                col[C] ^= ans;
                block[B] ^= ans;
                board[R][C] = (char)(i + '1');
                backstracking(board, row, col, block, pos + 1);
                if(flag) return;
                row[R] ^= ans;
                col[C] ^= ans;
                block[B] ^= ans;
                board[R][C] = '.';
            }
            choice >>= 1;
        }
    }
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
    flag = false;
    int row[9] = { 0 };
    int col[9] = { 0 };
    int block[9] = { 0 };
    for(int R = 0; R < 9; R++) {
        for(int C = 0; C < 9; C++) {
            if(board[R][C] == '.') continue;
            int tmp = (1 << (board[R][C] - '0') >> 1);
            int B = (C / 3) * 3 + R / 3;
            row[R] |= tmp;
            col[C] |= tmp;
            block[B] |= tmp;
        }
    }
    backstracking(board, row, col, block, 0);
}