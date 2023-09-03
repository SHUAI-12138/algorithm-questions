//
// Created by shuai on 2023/9/3.
//
#include<string.h>


int lengthOfLastWord(char * s){
    int end = strlen(s);
    int i = end;
    while(s[--i] == ' ');
    end = i;
    while(i > 0 && s[--i] != ' ');
    return end - i + (i == 0 && s[i] != ' ');
}
