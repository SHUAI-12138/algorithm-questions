//
// Created by shuai on 2023/8/16.
//

#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1 = haystack.size();
        int l2 = needle.size();
        if(l2 > l1) return -1;
        vector<int> next = getNext(needle);
        if(next.empty()) return -1;
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
    }

    vector<int> getNext(string str) {
        int len = str.size();
        vector<int> next;
        if(len == 0) return next;
        next.push_back(-1);
        if(len == 1) return next;
        next.push_back(0);
        if(len == 2) return next;
        int j = 0;
        while(next.size() <= len) {
            if(str[next.size() - 1] == str[j]) {
                next.push_back(++j);
            } else if(next[j] == -1) {
                next.push_back(0);
            } else {
                j = next[j];
            }
        }
        return next;
    }
};

int main() {
    Solution solution;
    vector<int> next = solution.getNext("aabaaac\0");
    for(int i = 0; i < 7; i++) {
        cout << next[i] << " " ;
    }
    return 0;
}