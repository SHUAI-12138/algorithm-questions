//
// Created by shuai on 2023/8/24.
//

#include<iostream>
#include<vector>
#include<stack>

using namespace std;



// 栈 执行时间 8 ms
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> container;
        int len = height.size();
        int max_pos = 0;
        int res = 0;
        for(int i = 0; i < len; i++) {
            if(height[i] < height[max_pos] || container.empty()) {
                container.push(height[i]);
                if(container.empty()) {
                    max_pos = i;
                }
            } else {
                if(i - max_pos < 2) {
                    while(!container.empty()) container.pop();
                    container.push(height[i]);
                    max_pos = i;
                } else {
                    res += (i - max_pos - 1) * height[max_pos];
                    int wall = container.top();
                    container.pop();
                    while(!container.empty()) {
                        res -= wall;
                        wall = container.top();
                        container.pop();
                    }
                    container.push(height[i]);
                    max_pos = i;
                }
            }
        }
        if(container.size() < 2) {
            return res;
        } else {
            vector<int> right;
            while(!container.empty()) {
                right.push_back(container.top());
                container.pop();
            }
            return res + trap(right);
        }


        return res;
    }
};




// 递归，执行时间长，1100ms
class SolutionElder {
public:

    int leftPartTrap(vector<int>& height, int right) {
        if(right < 2) {
            return 0;
        }
        int left = 0;
        for(int i = 1; i < right; i++) {
            if(height[i] > height[left]) {
                left = i;
            }
        }
        int res = 0;
        if(right - left > 1) res = height[left] * (right - left - 1);
        for(int i = left + 1; i < right; i++) {
            res -= height[i];
        }
        return res + leftPartTrap(height, left);
    }

    int rightPartTrap(vector<int>& height, int left) {
        int len = height.size();
        if(left > len - 3) {
            return 0;
        }
        int right = len - 1;
        for(int i = len - 2; i > left; i--) {
            if(height[i] > height[right]) {
                right = i;
            }
        }
        int res = 0;
        if(right - left > 1) res = height[right] * (right - left - 1);
        for(int i = left + 1; i < right; i++) {
            res -= height[i];
        }
        return res + rightPartTrap(height, right);
    }

    int trap(vector<int>& height) {
        int len = height.size();
        if(len < 3) return 0;
        int max = 0, max_second = 0;
        for(int i = 1; i < len; i++) {
            if(height[i] > height[max]) {
                max_second = max;
                max = i;
            }
        }
        if(max == 0) {
            max_second = 1;
            for(int i = 2; i < len; i++) {
                if(height[i] > height[max_second]) {
                    max_second = i;
                }
            }
        }
        int left = 0, right = 0;
        if(max < max_second) {
            left = max;
            right = max_second;
        } else {
            left = max_second;
            right = max;
        }
        int res = 0;
        if(right - left > 1) res = height[max_second] * (right - left - 1);
        for(int i = left + 1; i < right; i++) {
            res -= height[i];
        }
        return res += leftPartTrap(height, left) + rightPartTrap(height, right);
    }
};

int main() {
    vector<int> height{5, 4, 1, 2};
    Solution solution;
    cout << solution.trap(height) << endl;
    return 0;
}