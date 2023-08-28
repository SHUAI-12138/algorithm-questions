//
// Created by shuai on 2023/8/28.
//
#include<string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.size();
        int lenp = p.size();
        int i = 0, j = 0;
        int s_star = -1, p_star = -1;
        while(i < lens) {
            if(j < lenp && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            } else if(j < lenp && p[j] == '*') {
                s_star = i;
                p_star = j++;
            } else if(s_star >= 0){
                i = ++s_star;
                j = p_star + 1;
            } else return false;
        }
        while(j < lenp && p[j] == '*') j++;
        return j == lenp;
    }
};