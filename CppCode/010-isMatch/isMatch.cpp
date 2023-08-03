
#include<string>
#include<iostream>
#include<stdbool.h>
#include<vector>

using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s = s.length();
        int len_p = p.length();
        // 使用vector申请动态二维数组内存空间
        vector<vector<bool>> dp(len_s + 1, vector<bool>(len_p + 1, false));

        // 初始化
        dp[0][0] = true;
        for(int j = 1; j <= len_p; j++) {
            if(p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // dp变化
        for(int i = 1; i <= len_s; i++) {
            for(int j = 1; j <= len_p; j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if(p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || ((s[i -1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                }
            }
        }

        return dp[len_s][len_p];
    }

};


int main() {
    string s = "aa";
    string p = ".*";
    Solution solution;
    solution.isMatch(s, p) ? cout << "true" : cout << "false";
    cout << endl;

    return 0;
}