//
// Created by shuai on 2023/9/3.
//
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.size();
        int i = end;
        while(s[--i] == ' ');
        end = i;
        while(i > 0 && s[--i] != ' ');
        return end - i + (i == 0 && s[i] != ' ');
    }
};