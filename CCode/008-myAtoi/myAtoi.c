
#include<stdio.h>
#include<stdlib.h>

int myAtoi(char * s){
    if(s[0] == '\0') {
        return 0;
    }
    int num = 0;
    int p = 0;
    int flag = 0;
    while(s[p] != '\0') {
        if(flag == 0) {
            if(s[p] == '-') {
                flag = -1;
                p++;
                continue;
            } else if(s[p] == '+') {
                flag = 1;
                p++;
                continue;
            } else if(s[p] >= '0' && s[p] <= '9'){
                flag = 1;
                continue;
            }  else if(s[p] != ' ') {
                return 0;
            }
            p++;
            continue;
        }

        if (flag) {
            int tmp = s[p] - '0';
            tmp = num * 10 + tmp;
            if(num > tmp) {
                return 0x7fff;
            }
            num = tmp;
            if(s[p + 1] >= '0' && s[p + 1] <= '9') {
                p++;
                continue;
            } else {
                break;
            }
        }
    }

    return num * flag;
}

int main() {
    char* s1 = " ";
    char* s2 = "  -42";
    char* s3 = "with words 987";
    int tmp1 = myAtoi(s1);
    int tmp2 = myAtoi(s2);
    int tmp3 = myAtoi(s3);
    printf("%d\n", tmp1);
    printf("%d\n", tmp2);
    printf("%d\n", tmp3);
    return 0;
}