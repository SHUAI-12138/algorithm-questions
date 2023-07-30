
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* longestPalindrome(char* s){
    if(strlen(s) < 2) {
        return s;
    }
    char* ret;
    int left = 0, right = 0;
    int pre = 1, cur = 0;
    int length = 0, pos = 0;
    while(s[pre] != '\0') {
        left = cur;
        right = pre;
        if(s[left] == s[right]) {
            int tmp = right - left + 1;
            left--;
            right++;
            while(left >= 0 && s[right] != '\0' && s[left] == s[right]){
                tmp +=2;
                left--;
                right++;
            }
            if(length < tmp){
                length = tmp;
                pos = left + 1;
            }
        }
        left = cur;
        right = pre;
        // printf("left = %d  right = %d\n", left, right);
        // printf("s[left] = %c  s[left] = %c\n", s[left], s[right]);
        if(s[++right] != '\0' && s[right] == s[left]) {
            // printf("%d\n", right);
            int tmp = right - left + 1;
            left--;
            right++;
            while(left >= 0 && s[right] != '\0' && s[left] == s[right]){
                tmp +=2;
                left--;
                right++;
            }
            if(length < tmp){
                length = tmp;
                pos = left + 1;
            }
        }
        cur++;
        pre++;

    }
    if(length == 0) {
        ret = (char*)malloc(sizeof(char) * 2);
        ret[0] = s[0];
        ret[1] = '\0';
        return ret;
    }
    // printf("%d\n", length);
    ret = (char*)malloc(sizeof(char) * (length + 1));
    ret[length] = '\0';
    for(int i = 0; i < length; i++) {
        ret[i] = s[pos + i];
    }
    return ret;



}

int main(){
    char* ch = "bbc";
    char* result = longestPalindrome(ch);
    puts(result);
    return 0;
}