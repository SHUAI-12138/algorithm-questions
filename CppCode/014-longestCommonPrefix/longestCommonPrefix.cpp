
#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int pos = 0;
        int flag = 0;
        int len = strs.size();

        while(1) {
            char ch = strs[0][pos];
            for(int i = 0; i < len; i++) {
                if(strs[i][pos] != ch || pos == strs[i].length()) {
                    flag = 1;
                    break;
                }
            }

            if(flag) {
                break;
            }
            pos++;
        }

        if(pos == 0) return "";
        string ret = strs[0].substr(0, pos);
        return ret;
    }
};


int main() {
    vector<string> strs;
    strs.push_back("flower");
    strs.push_back("fly");
    strs.push_back("flow");
    Solution solution;
    cout << solution.longestCommonPrefix(strs) << endl;;
    return 0;
}