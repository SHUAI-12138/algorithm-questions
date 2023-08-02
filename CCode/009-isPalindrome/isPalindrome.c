
#include<stdio.h>
#include<stdlib.h>

int isPalindrome(int x) {
    if(x == 0) return 1;
    if(x < 0 || x % 10 == 0) return 0;
    int newNum = 0;
    int oldNum = x;
    while(oldNum) {
        newNum = newNum * 10 + oldNum % 10;
        oldNum /= 10;
        if(newNum > 0x7fffffff / 10 || (newNum == 0x7fffffff / 10 && oldNum > 7)) return 0;
        if(newNum == oldNum || newNum == oldNum / 10) return 1;
    }
    return newNum == x ? 1 : 0;
}

int main() {
    printf("%d\n", isPalindrome(1234321));
    printf("%d\n", isPalindrome(1233521));
    printf("%d\n", isPalindrome(1000000001));
    return 0;
}

