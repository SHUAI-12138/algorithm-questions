
#include<iostream>
#include<vector>

using namespace std;

int getMin(int a, int b){
    return a <= b ? a : b;
}

class Solution{
public:
    static double findKthNumber(vector<int>& nums1, vector<int>& nums2, int p1, int p2, int K, int N) {
        
        if(p1 >= nums1.size()) {
            if(N == 1) { 
                return nums2[p2 + K -1];
            } else {
                return (nums2[p2 + K - 1] + nums2[p2 + K]) / 2.0;
            }
        }
        if(p2 >= nums2.size()){
            if(N == 1){
                return nums1[p1 + K -1];
            } else {
                return (nums1[p1 + K -1] + nums1[p1 + K]) / 2.0;
            }
        }
        if(K == 1){
            if(N == 1) {
                return getMin(nums1[p1], nums2[p2]);
            } else {
                int tmp1 = 0;
                if(nums1[p1] <= nums2[p2]) {
                    tmp1 = nums1[p1++];
                } else {
                    tmp1 = nums2[p2++];
                }
                return (tmp1 + Solution::findKthNumber(nums1, nums2, p1, p2, 1, 1)) / 2.0;
            }
        }

        int inc1 = getMin(p1 + (K / 2) - 1, nums1.size() - 1);
        int inc2 = getMin(p2 + (K / 2) - 1, nums2.size() - 1);
        if(nums1[inc1] <= nums2[inc2]) {
            return Solution::findKthNumber(nums1, nums2, inc1 + 1, p2, K - (inc1 - p1 + 1), N);
        } else {
            return Solution::findKthNumber(nums1, nums2, p1, inc2 + 1, K - (inc2 - p2 + 1), N);
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int len1 = nums1.size();
        int len2 = nums2.size();
        int K = (len1 + len2 + 1) / 2;
        int N = (len1 + len2) % 2;

        return Solution::findKthNumber(nums1, nums2, 0, 0, K, N);
    }

};

int main() {

    vector<int> nums1 = {2, 3, 4};
    vector<int> nums2 = {1};
    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2);

    return 0;
}

