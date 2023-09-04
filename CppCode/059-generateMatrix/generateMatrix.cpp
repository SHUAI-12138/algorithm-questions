#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int flag = 1;
        int N = n * n;
        int x = 0, y = -1;
        for(int i = 1; i <= N; i++) {
            switch (flag % 4) {
                case 1 :
                    ans[x][++y] = i;
                    if (y == n - flag / 4 - 1) flag++;
                    break;
                case 2 :
                    ans[++x][y] = i;
                    if (x == n - flag / 4 - 1) flag++;
                    break;
                case 3 :
                    ans[x][--y] = i;
                    if (y == flag / 4) flag++;
                    break;
                case 0 :
                    ans[--x][y] = i;
                    if (x == flag / 4) flag++;
            }
        }
        return ans;
    }
};