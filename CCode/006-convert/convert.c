
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * convert(char * s, int numRows){
    int strLen = strlen(s);
    if(strLen <= numRows || numRows == 1) {
        return s;
    }
    int turn = 2 * numRows - 2;
    char* ret = (char*)malloc(sizeof(char) * (strLen + 1));
    ret[strLen] = '\0';
    int cur = 0;
    for(int row = 0; row < numRows; row++) {
        for(int j = 0; j * turn + row < strLen && cur < strLen; j++) {
            ret[cur++] = s[j * turn + row];
            if(row != 0 && row != numRows - 1){
                if((j + 1) * turn - row < strLen){
                    ret[cur++] = s[(j + 1) * turn - row];
                } else {
                    break;
                }
            } 
        }
    }
    return ret;
}

int main() {
    char* s = "PAYPALISHIRING";
    char* ret = convert(s, 3); // PAHNAPLSIIGYIR
    puts(ret);
    free(ret);
    ret = convert(s, 4); // PINALSIGYAHRPI
    puts(ret);
    free(ret);
    return 0;
}