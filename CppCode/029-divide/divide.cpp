//
// Created by shuai on 2023/8/16.
//

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(dividend == divisor) return 1;
        if(dividend == -2147483648 && divisor == -1) return 2147483647;
        if(divisor == -2147483648) return 0;
        int flag = -1;
        if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
            flag = 1;
        }
        if(dividend > 0) dividend = -dividend;
        if(divisor > 0) divisor = -divisor;
        int n = 1;
        int num = divisor;
        while(num >= (-2147483648 >> 1) && (num << 1) >= dividend) {
            num <<= 1;
            n <<= 1;
        }
        int res = 0;
        while(dividend < 0 && num <= divisor) {
            while(dividend <= num) {
                dividend -= num;
                res += n;
            }
            if(dividend > divisor) return flag * res;
            num >>= 1;
            n >>= 1;
        }
        return flag * res;
    }
};