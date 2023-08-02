
#include<string>
#include<iostream>
#include<stdbool.h>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0) return true;
        if(x < 0 || x % 10 == 0) return false;
        int oldNum = x;
        int newNum = 0;
        while(oldNum > 0) {
            newNum = newNum * 10 + (oldNum % 10);
            oldNum /= 10;
            if(newNum > 0x7fffffff / 10 || (newNum == 0x7fffffff / 10 && oldNum > 7)) return false;
            if(newNum == oldNum || newNum == oldNum / 10) return true;
        }
        return newNum == x ? true : false;
    }
};

int main(){
    Solution solution;
    cout << solution.isPalindrome(123421) << endl;
    return 0;
}