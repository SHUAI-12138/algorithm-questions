
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool isValid(char * s){
    int len = strlen(s);
    if(len % 2) return false;
    char* stack = (char*)malloc(sizeof(char) * (len >> 1));
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