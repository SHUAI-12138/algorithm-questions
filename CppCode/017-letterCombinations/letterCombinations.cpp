
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) return result;

        unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        int depth = digits.length();
        string res;
        backTracking(digits, result, 0, depth, phoneMap, res);
        return result;
    }
    void backTracking(string digits, vector<string>& result, int index, int depth, unordered_map<char, string> phoneMap, string& res) {
        if(index == depth) {
            result.push_back(res);
            return;
        }
        const string& temp = phoneMap.find(digits[index])->second;
        for(int i = 0; i < temp.length(); i++) {
            res.push_back(temp[i]);
            backTracking(digits, result, index + 1, depth, phoneMap, res);
            res.pop_back();
        }
    }
};