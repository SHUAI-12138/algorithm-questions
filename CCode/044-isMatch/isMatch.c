//
// Created by shuai on 2023/8/28.
//
#include<string.h>
#include<stdbool.h>

bool isMatch(char * s, char * p){
    int lens = strlen(s);
    int lenp = strlen(p);
    int i = 0, j = 0;
    int s_star = -1, p_star = -1;
    while(i < lens) {
        if(j < lenp && (s[i] == p[j] || p[j] == '?')) {
            ++i;
            ++j;
        } else if(j < lenp && p[j] == '*') {
            s_star = i;
            p_star = j++;
        } else if(s_star >= 0) {
            i = ++s_star;
            j = p_star + 1;
        } else return false;
    }
    while(j < lenp && p[j] == '*') ++j;
    return j == lenp;
}