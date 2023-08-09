
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static char phoneMap[10][5] = {"\0", "\0", "abc\0", "def\0", "ghi\0" , "jkl\0", "mno\0", "pqrs\0", "tuv\0", "wxyz\0"};

void backTracking(char* digits, int* answer, int index, int depth, char** result, int* returnSize) {
    if(index == depth) {
        result[*returnSize] = (char*)malloc(sizeof(char) * (depth + 1));
        for(int i = 0; i < depth; i++) {
            result[*returnSize][i] = phoneMap[digits[i] - '0'][answer[i]];
        }
        result[*returnSize][depth] = '\0';
        (*returnSize)++;
        return;
    }
    for(answer[index] = 0;  phoneMap[digits[index] - '0'][answer[index]] != '\0'; answer[index]++) {
        backTracking(digits, answer, index + 1, depth, result, returnSize);
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    int depth = strlen(digits);
    *returnSize = 0;
    if(depth == 0 || digits == NULL) return NULL;
    int answer[5] = { 0 };
    int num = pow(4, depth); 
    char** result = (char**)malloc(sizeof(char*) * num);
    backTracking(digits, answer, 0, depth, result, returnSize);
    return result;
}