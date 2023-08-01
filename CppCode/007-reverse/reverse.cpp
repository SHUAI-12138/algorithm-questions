
#include<iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x < 10 && x > -10) {
            return x;
        }

        int num = x;
        int sum = 0;

        while(num) {
            if(sum > 214748364 || (sum == 214748364 && num > 7)) {
                return 0;
            }
            if(sum < -214748364 || (sum == -214748364 && num < -8)) {
                return 0;
            }
            sum = sum * 10 + num % 10;
            num /= 10;
        }

        return sum;
    }
};

int main() {
    Solution solution;
    cout << solution.reverse(120) << endl;
    return 0;
}

