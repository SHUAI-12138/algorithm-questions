//
// Created by shuai on 2023/8/22.
//

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int row[9] = { 0 };
    int col[9] = { 0 };
    int block[9] = { 0 };
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][j] == '.') continue;
            int tmp = 1;
            tmp = (tmp << (board[i][j] - '0')) >> 1;
            int pos = 3 * (j / 3) + i / 3;
            if((row[i] & tmp) > 0 || (col[j] & tmp) > 0 || (block[pos] & tmp) > 0) return false;
            row[i] |= tmp;
            col[j] |= tmp;
            block[pos] |= tmp;
        }
    }
    return true;
}