
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if(len <= numRows || numRows == 1) return s;
        int turn = (numRows << 1) - 2;
        string ret = "";

        for(int row = 0; row < numRows; row++) {
            for(int j = 0; j * turn + row < len; j++) {
                ret += s.substr(j * turn + row, 1);
                if(row != 0 && row != numRows - 1) {
                    if((j + 1) * turn - row < len) {
                        ret += s.substr((j + 1) * turn - row, 1);
                    } else {
                        break;
                    }
                }
            }
        }

        return ret;
    }

    string convertOptimize(string s, int numRows) {
        int len = s.length();
        if(len <= numRows || numRows == 1) {
            return s;
        }

        int turn = (numRows * 2) - 2;
        int cur = 0;
        char* ch = (char*)malloc(sizeof(char) * (len + 1));
        ch[len] = '\0';

        for(int row = 0; row < numRows; row++) {
            for(int j = 0; j * turn + row < len && cur < len; j++) {
                ch[cur++] = s[j * turn + row];
                if(row != 0 && row != numRows - 1) {
                    if((j + 1) * turn - row < len) {
                        ch[cur++] = s[(j + 1) * turn - row];
                    } else {
                        break;
                    }
                }
            }
            
        }

        return ch;
    }
};

int main() {
    string s = "PAYPALISHIRING";
    Solution solution;
    cout << "PAHNAPLSIIGYIR\tPINALSIGYAHRPI\t(answer)" << endl;
    cout << solution.convert(s, 3) << "\t" << solution.convert(s, 4) << endl; 
    cout << solution.convertOptimize(s, 3) << "\t" << solution.convertOptimize(s, 4) << endl;
    return 0;
}