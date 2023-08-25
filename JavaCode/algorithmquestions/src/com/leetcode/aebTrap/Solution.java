package com.leetcode.aebTrap;

import java.util.Stack;


// 栈 运行时间 13 ms
class Solution {
    // 动态规划 运行时间 1 ms
    public int trap(int[] height) {
        int n = height.length;
        int[] leftMax = new int[n];
        leftMax[0] = height[0];
        for(int i = 1; i < n; i++) {
            leftMax[i] = Math.max(leftMax[i - 1], height[i]);
        }
        int[] rightMax = new int[n];
        rightMax[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; --i) {
            rightMax[i] = Math.max(rightMax[i + 1], height[i]);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            res += Math.min(rightMax[i], leftMax[i]) - height[i];
        }
        return res;
    }


    public int trapElder(int[] height) {
        Stack<Integer> stack = new Stack<>();
        int maxPos = 0;
        int res = 0;
        for(int i = 0; i < height.length; i++) {
            if(height[i] < height[maxPos]) {
                stack.push(height[i]);
            } else {
                if(i - maxPos < 2) {
                    while(!stack.empty()) {
                        stack.pop();
                    }
                } else {
                    res += (i - maxPos - 1) * height[maxPos];
                    int wall = stack.pop();
                    while(!stack.empty()) {
                        res -= wall;
                        wall = stack.pop();
                    }
                }
                stack.push(height[i]);
                maxPos = i;
            }
        }
        if(stack.size() < 2) return res;
        int[] right = new int[stack.size()];
        for(int i = 0; i < right.length; i++) {
            right[i] = stack.pop();
        }
        return res + trap(right);
    }
}
