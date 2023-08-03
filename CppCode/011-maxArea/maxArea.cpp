
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = height.size() - 1;
        int left = 0;

        int max = 0;
        int area = 0;

        while(left < right) {
            if(height[left] >= height[right]) {
                area = height[right] * (right - left); 
                right--;
            } else {
                area = height[left] * (right - left);
                left++;
            }
            if(max < area) {
                max = area;
            }
        }

        return max;
    }
};

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution solution;
    cout << solution.maxArea(height) << endl;
    return 0;
}