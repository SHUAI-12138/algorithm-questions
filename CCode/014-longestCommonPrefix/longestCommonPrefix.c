
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int pos = 0;
    int flag = 0;

    while(1) {
        char ch = strs[0][pos];
        printf("%c\n", ch);
        for(int i = 0; i < strsSize; i++) {
            if(strs[i][pos] != ch || strs[i][pos] == '\0') {
                flag = 1;
                break;
            }
        }
        if(flag) {
            break;
        }
        pos++;
    }

    if(pos == 0) return (char*)"";

    char* ret = (char*)malloc(sizeof(char) * (pos + 1));
    ret[pos] = '\0';
    
    for(int i = 0; i < pos; i++) {
        ret[i] = strs[0][i];
    }

    return ret;


}

int main() {
    char** strs;
    strs[0] = (char*)"flower";
    strs[0] = (char*)"fly";
    strs[0] = (char*)"flow";
    char * tmp = longestCommonPrefix(strs, 3);
    printf("%s\n", tmp);
    return 0;
}