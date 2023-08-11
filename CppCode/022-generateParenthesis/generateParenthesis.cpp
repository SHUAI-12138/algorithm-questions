
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string res;
        vector<string> result;
        backTracking(0, 0, n, res, result);
        return result;
    }

    void backTracking(int left, int right, int n, string& res, vector<string>& result) {
        if(right == n) {
            result.push_back(res);
            return;
        }
        if(left < n) {
            res.push_back('(');
            backTracking(left + 1, right, n, res, result);
            res.pop_back();
        }
        if(right < left) {
            res.push_back(')');
            backTracking(left, right + 1, n, res, result);
            res.pop_back();
        }
    }}
};