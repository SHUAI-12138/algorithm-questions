
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int strLen = s.length();
        if(strLen < 2) {
            return s;
        }
        int left = 0, right = 0;
        int pre = 1;
        int length = 0, pos = 0;

        for(; pre < strLen; pre++) {
            left = pre - 1;
            right = pre;
            if(s[left] == s[right]) {
                int tmp = 2;
                right++;
                left--;
                while(left >= 0 && right < strLen && s[left] == s[right]) {
                    tmp += 2;
                    left--;
                    right++;
                }
                if(tmp > length) {
                    pos = left + 1;
                    length = tmp;
                }
            }

            left = pre - 1;
            right = pre;
            if(++right < strLen && s[right] == s[left]) {
                int tmp = 3;
                right++;
                left--;
                while(left >= 0 && right < strLen && s[left] == s[right]) {
                    tmp += 2;
                    left--;
                    right++;
                }
                if(tmp > length) {
                    pos = left + 1;
                    length = tmp;
                }
            }
            if(length == strLen) return s;
        }
        if(length == 0) {
            string ret = s.substr(0, 1);
            return ret;
        }
        string ret = s.substr(pos, length);
        return ret;
    }
};

int main() {
    string s = "ab";
    Solution solution;
    cout << solution.longestPalindrome(s); 
    return 0;
}