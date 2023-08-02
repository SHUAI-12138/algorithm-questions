
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int p = 0;
        int num = 0;
        int flag = 0;
        
        while(s[p] != '\0') {
            while(s[p] == ' ') {
                p++;
            }
            if(flag == 0) {
                if(s[p] == '+') {
                flag = 1;
                p++;
                } else if(s[p] == '-') {
                    flag = -1;
                    p++;
                } else if(s[p] >= '0' && s[p] <= '9') {
                    flag = 1;
                }
            }
            if(s[p] < '0' || s[p] > '9') {
                break;
            }
            int tmp = s[p] - '0';
            if(num > 0x7fffffff / 10 || (num >= 0x7fffffff / 10 && tmp > 7)) {
                return flag == 1 ? 0x7fffffff : 0x80000000;
            }
            num = num * 10 + tmp;
            if(s[p + 1] <= '9' && s[p + 1] >= '0') {
                p++;
            } else {
                break;
            }
        }

        return flag * num;
    }
};

int main() {
    Solution solution;
    cout << solution.myAtoi("42") << endl;
    cout << solution.myAtoi("  -42") << endl;
    cout << solution.myAtoi("+0 -42") << endl;
    cout << solution.myAtoi("with42") << endl;
    return 0;
}