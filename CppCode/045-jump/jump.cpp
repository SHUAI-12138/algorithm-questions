//
// Created by shuai on 2023/8/28.
//
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int step = 0, step_length = 0, cur = 0;
        while(cur < nums.size()) {
            step_length = nums[cur];
            int longest = step_length + cur;
            int next_cur = longest;
            if(cur + step_length >= nums.size() - 1) return step + 1;
            for(int i = 1; i <= step_length; i++) {
                int tmp = nums[cur + i] + i + cur;
                if(tmp > longest) {
                    longest = tmp;
                    next_cur = cur + i;
                }
            }
            cur = next_cur;
            step++;
        }
        return step;
    }
};


// 动态规划
class SolutionByDP {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 2147483647);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 1; i + j < n && j <= nums[i]; j++) {
                dp[i + j] = min(dp[i] + 1, dp[i + j]);
            }
        }
        return dp[n - 1];
    }
};

int main() {
    vector<int> nums{1,1,1,1};
    Solution solution;
    cout << solution.jump(nums) << endl;
}
