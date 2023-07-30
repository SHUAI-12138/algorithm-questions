package com.leetcode.aadFindMedianSortedArrays;

public class Solution {

    public static void main(String[] args) {
        int[] nums1 = new int[] { 1, 2 };
        int[] nums2 = new int[] { 3, 4 };
        System.out.println(Solution.findMedianSortedArrays(nums1, nums2));
//        System.out.println(Solution.findMedianSortedArrays1(nums1, nums2));
    }

    // 递归
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len = nums1.length + nums2.length;
        int K = (len + 1) / 2;
        return Solution.findKthDecimal(nums1, nums2, 0, 0, K, len % 2);
    }

    public static double findKthDecimal(int[] nums1, int[] nums2, int p1, int p2, int K, int N) {
        if (p1 >= nums1.length) {
            if (N == 1) {
                return nums2[p2 + K - 1];
            } else {
                return (nums2[p2 + K - 1] + nums2[p2 + K]) / 2.0;
            }
        }
        if (p2 >= nums2.length) {
            if (N == 1) {
                return nums1[p1 + K - 1];
            } else {
                return (nums1[p1 + K - 1] + nums1[p1 + K]) / 2.0;
            }
        }
        if (K == 1) { // 此时已经指向中位数
            int tmp1 = Math.min(nums1[p1], nums2[p2]);
            if (N == 1) {
                return tmp1;
            } else if (N == 0) {
                if (nums1[p1] == tmp1) {
                    p1++;
                } else {
                    p2++;
                }
                double tmp2 = Solution.findKthDecimal(nums1, nums2, p1, p2, 1, 1);
                return (tmp1 + tmp2) / 2;
            }
        }

        int inc1 = (p1 + (K / 2) - 1) < nums1.length ? (p1 + (K / 2) - 1) : nums1.length - 1;
        int inc2 = (p2 + (K / 2) - 1) < nums2.length ? (p2 + (K / 2) - 1) : nums2.length - 1;
        if (nums1[inc1] <= nums2[inc2]) {
            return Solution.findKthDecimal(nums1, nums2, inc1 + 1, p2, K - (inc1 - p1 + 1), N);
        } else {
            return Solution.findKthDecimal(nums1, nums2, p1, inc2 + 1, K - (inc2 - p2 + 1), N);
        }

    }

//    // 非递归，循环
//    public static double findMedianSortedArrays1(int[] nums1, int[] nums2) {
//        int len1 = nums1.length;
//        int len2 = nums2.length;
//        int K = (len1 + len2 + 1) / 2;
//        int p1 = 0;
//        int p2 = 0;
//        int N = (len1 + len2) % 2;
//        while (p1 < len1 && p2 < len2 && K != 1) {
//            int inc1 = (p1 + (K / 2) - 1) < len1 ? (p1 + (K / 2) - 1) : len1 - 1;
//            int inc2 = (p2 + (K / 2) - 1) < len2 ? (p2 + (K / 2) - 1) : len2 - 1;
//            if (nums1[inc1] <= nums2[inc2]) {
//                p1 = inc1 + 1;
//                K -= inc1 - p1 + 1;
//            } else {
//                p2 = inc2 + 1;
//                K -= inc2 - p2 + 1;
//            }
//        }
//        if (N == 1) {
//            if (p1 >= len1)
//                return nums2[p2 + K - 1];
//            if (p2 >= len2)
//                return nums2[p1 + K - 1];
//            return Math.min(nums1[p1], nums2[p2]);
//        }
//        if (p1 >= len1)
//            return (nums2[p2 + K - 1] + nums2[p2 + K]) / 2.0;
//        if (p2 >= len2)
//            return (nums1[p1 + K - 1] + nums1[p1 + K]) / 2.0;
//        int sum = 0;
//        for (int i = 0; i < 2; i++) {
//            if (nums1[p1] <= nums2[p2]) {
//                sum += nums1[p1];
//                p1++;
//            } else {
//                sum += nums2[p2];
//                p2++;
//            }
//            if (p1 == len1)
//                return (sum + nums2[p2]) / 2.0;
//            if (p2 == len2)
//                return (sum + nums1[p1]) / 2.0;
//        }
//        return sum / 2.0;
//    }
}
