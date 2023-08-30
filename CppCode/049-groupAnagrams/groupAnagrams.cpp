//
// Created by shuai on 2023/8/30.
//
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            map[key].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto it : map) {
            res.push_back(it.second);
        }
        return res;
    }
};