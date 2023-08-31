package com.leetcode.afeSpiralOrder;


import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int R = matrix.length, C = matrix[0].length;
        int len = R * C;
        List<Integer> res = new ArrayList<>();
        int flag = 1;
        int row = 0, col = -1;
        for(int i = 0; i < len; i++) {

            switch(flag % 4) {
                case 1:
                    col++;
                    if(col == C - 1 - flag / 4) flag++;
                    break;
                case 2:
                    row++;
                    if(row == R - 1 - flag / 4) flag++;
                    break;
                case 3:
                    col--;
                    if(col == flag / 4) flag++;
                    break;
                case 0:
                    row--;
                    if(row == flag / 4) flag++;
                    break;
            }
            res.add(matrix[row][col]);
        }
        return res;
    }
}
