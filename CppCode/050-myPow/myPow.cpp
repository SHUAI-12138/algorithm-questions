//
// Created by shuai on 2023/8/31.
//

class Solution {
public:
    double pow_process(double x, int n) {
        if(n == 0) return 1;
        if(n == -1) return x;

        if(n % 2 == 0) {
            double tmp = pow_process(x, n >> 1);
            return tmp * tmp;
        } else {
            double tmp = pow_process(x, (n >> 1) + 1);
            return x * tmp * tmp;
        }
    }
    double myPow(double x, int n) {
        if(n >= 0) return pow_process(x, -n);
        return 1/pow_process(x, n);
    }
};