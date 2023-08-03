package com.leetcode.abaMaxArea;

public class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;

        int max = 0;
        int area = 0;

        while(left < right) {
            if(height[left] <= height[right]) {
                area= height[left] * (right - left);
                left++;
            } else {
                area = height[right] * (right - left);
                right--;
            }
            max = Math.max(max, area);
        }

        return max;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] height = new int[]{1,8,6,2,5,4,8,3,7};
        System.out.println(solution.maxArea(height));
    }
}
