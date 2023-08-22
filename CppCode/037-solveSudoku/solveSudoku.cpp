//
// Created by shuai on 2023/8/22.
//

#include<vector>
#include<iostream>
#include<stdbool.h>

using namespace std;

static bool flag = false;

class Solution {
public:

    void backtracking(vector<vector<char>>& board, int* row, int* col, int* block, int pos) {
        if(pos == 81) {
            flag = true;
            //cout << flag << endl;
            return;
        }
        int R = pos / 9;
        int C = pos % 9;
        if(board[R][C] != '.') {
            backtracking(board, row, col, block, pos + 1);
            return;
        } else {
            int B = R / 3 + ((C / 3) * 3);
            int choice = (row[R] | col[C] | block[B]) ^ 511;
            //cout << pos << ": " << choice << endl;
            if(choice == 0) return;
            for(int i = 0; choice; i++) {
                if(choice % 2) {
                    unsigned int ans = (1 << i);
                    row[R] ^= ans;
                    col[C] ^= ans;
                    block[B] ^= ans;
                    board[R][C] = (char)(i + '1');
                    //cout << pos << ": " << board[R][C] << endl;
                    backtracking(board, row, col, block, pos + 1);
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
    void solveSudoku(vector<vector<char>>& board) {
        flag = false;
        int row[9] = { 0 };
        int col[9] = { 0 };
        int block[9] = { 0 };
        // 记录每一行，每一列，每一分块中已经存在的元素
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
        backtracking(board, row, col, block, 0);
    }
};