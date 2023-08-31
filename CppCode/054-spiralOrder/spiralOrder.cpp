//
// Created by shuai on 2023/8/31.
//
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size();
        int len = R * C;
        vector<int> res(len);
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
            res[i] = matrix[row][col];
        }
        return res;
    }
};