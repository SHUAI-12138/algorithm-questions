//
// Created by shuai on 2023/8/30.
//

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int L = 0;
    int R = matrixSize - 1;
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

