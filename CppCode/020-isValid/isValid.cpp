
#include<string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if(len % 2 == 1) return false;
        char* stack = new char[len >> 1];
        int top = 0;
        for(int i = 0; i < len; i++) {
            char ch = s[i];
            if(ch == '(' || ch == '[' || ch == '{') {
                if(top == (len >> 1)) return false;
                stack[top++] = ch;
                continue;
            }
            if(top == 0) return false;
            char left = stack[--top];
            if(left == '(' && ch == ')') continue;
            else if(left == '[' && ch == ']') continue;
            else if(left == '{' && ch == '}') continue;
            else return false;
        }
        if(top == 0) return true;
        else return false;
    }
};