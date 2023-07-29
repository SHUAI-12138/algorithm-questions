
#include<stdio.h>
#include<stdlib.h>


double findKthNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int p1, int p2, int K, int N){

    if(p1 >= nums1Size) {
        if(N == 1) {
            return nums2[p2 + K - 1];
        } else {
            return (nums2[p2 + K -1] + nums2[p2 + K]) / 2.0;
        }
    }
    if(p2 >= nums2Size) {
        if(N == 1) {
            return nums1[p1 + K - 1];
        } else {
            return (nums1[p1 + K - 1] + nums1[p1 + K]) / 2.0;
        }
    }
    if(K == 1){
        if(N == 1) {
            return nums1[p1] <= nums2[p2] ? nums1[p1] : nums2[p2];
        } else {
            int tmp = 0;
            if(nums1[p1] <= nums2[p2]) {
                tmp = nums1[p1++];
            } else {
                tmp = nums2[p2++];
            }
            return (tmp + findKthNumber(nums1, nums1Size, nums2, nums2Size, p1, p2, 1, 1)) / 2.0;
        }
    }

    int inc1 = (p1 + K / 2 - 1) < nums1Size ? (p1 + K / 2 - 1) : nums1Size - 1;
    int inc2 = (p2 + K / 2 - 1) < nums2Size ? (p2 + K / 2 - 1) : nums2Size - 1;
    if(nums1[inc1] <= nums2[inc2]) {
        return findKthNumber(nums1, nums1Size, nums2, nums2Size, inc1 + 1, p2, K - (inc1 - p1 + 1), N);
    } else {
        return findKthNumber(nums1, nums1Size, nums2, nums2Size, p1, inc2 + 1, K - (inc2 - p2 + 1), N);
    }

}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int K = (nums1Size + nums2Size + 1) / 2;
    int N = (nums1Size + nums2Size) % 2;
    return findKthNumber(nums1, nums1Size, nums2, nums2Size, 0, 0, K, N);
}

int main(){
    int nums1[] = {1, 2};
    int nums2[] = {3, 4};
    int nums1Size = (int)sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = (int)sizeof(nums2) / sizeof(nums2[0]);
    printf("%lf", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));
    return 0;
}