package com.leetcode.adcSearch;

class Solution {

    public int findMin(int[] nums) {
        int len = nums.length;
        if(nums[0] < nums[len - 1]) return 0;
        if(len == 2) return 1;
        int left = 0;
        int right = len - 1;
        while(left < right) {
            int mid = ((right + left) >> 1);
            if(nums[mid] > nums[mid + 1]) {
                return mid + 1;
            } else if(nums[mid] < nums[mid - 1]) {
                return mid;
            } else if(nums[mid] > nums[0]) {
                left = mid;
            } else if(nums[mid] < nums[0]) {
                right = mid;
            }
        }
        return -1;
    }

    public int search(int[] nums, int target) {
        int len = nums.length;
        if(len == 0) return -1;
        if(len == 1) return nums[0] == target ? 0 : -1;
        int n = findMin(nums);
        System.out.println(n);
        if(nums[n] == target) return n;
        int left = 0;
        int right = 0;
        if(target > nums[0]) {
            right = n == 0 ? len - 1 : n - 1;
        } else if(target == nums[0]) {
            return 0;
        } else {
            if(n == 0) return -1;
            left = n;
            right = len - 1;
        }
        while(true) {
            int mid = ((right + left) >> 1);
            System.out.println(left + " " + mid + " " + right);
            if(nums[mid] == target) return mid;
            if(target < nums[mid]) {
                right = mid;
            } else {
                left =mid;
            }
            if(left + 1 >= right) break;
        }
        if(nums[left] == target) return left;
        if(nums[right] == target) return right;
        return -1;
    }

    public static void main(String[] args) {
        int[] nums = new int[]{3, 5, 1};
        Solution solution = new Solution();
        System.out.println(solution.search(nums, 0));
    }
}
