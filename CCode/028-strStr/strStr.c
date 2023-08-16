//
// Created by shuai on 2023/8/15.
//

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int* getNext(char* str, int len){
    int* next = (int*)malloc(sizeof(int) * len);
    next[0] = -1;
    if(len == 1) return next;
    next[1] = 0;
    if(len == 2) return next;
    int i = 2;
    int j = 0;
    while(i < len) {
        if(str[i - 1] == str[j]) {
            next[i++] = ++j;
        } else if(next[j] == -1){
            next[i++] = 0;
        } else {
            j = next[j];
        }
    }
    return next;
}

int strStr(char * haystack, char * needle){
    int l1 = strlen(haystack);
    int l2 = strlen(needle);
    if(l2 > l1 || (!l1 && !l2)) return -1;
    int* next = getNext(needle, l2);
    int i1 = 0, i2 = 0;
    while(i1 < l1 && i2 < l2) {
        if(haystack[i1] == needle[i2]) {
            i1++;
            i2++;
        } else if(next[i2] == -1) {
            i1++;
        } else {
            i2 = next[i2];
        }
    }
    return (i2 == l2) ? i1 - i2 : -1;
}

int main() {
    char* ch = "aabaaac\0";
    int* next = getNext(ch, 7);
    for(int i = 0; i < 7; i++) {
        printf("%d ", next[i]);
    }
    return 0;
}