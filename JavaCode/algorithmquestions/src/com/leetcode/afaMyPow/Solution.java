package com.leetcode.afaMyPow;

class Solution {
    public double process(double x, int n) {
        if(n == 0) return 1;
        if(n == -1) return x;

        if(n % 2 == 0) {
            double tmp = process(x, n >> 1);
            return tmp * tmp;
        } else {
            double tmp = process(x, (n >> 1) + 1);
            return x * tmp * tmp;
        }
    }
    public double myPow(double x, int n) {
        if(n >= 0) return process(x, -n);
        return 1/process(x, n);
    }
}
