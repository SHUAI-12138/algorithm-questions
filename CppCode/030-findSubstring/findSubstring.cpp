//
// Created by shuai on 2023/8/17.
//

#include<string>
#include<map>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int len = s.size();
        int wordLen = words[0].size();
        int wordsNum = words.size();
        unordered_map<string, int> target;
        for(int i = 0; i < wordsNum; i++) {
            unordered_map<string, int>::iterator it = target.find(words[i]);
            it == target.end() ? target[words[i]] = 1 : (it->second)++;
        }

        for(int i = 0; i < wordLen; i++) {
            int left = i;
            int right = i;
            int count = 0;
            unordered_map<string, int> m_map;
            while(right + wordLen <= len) {
                string str = s.substr(right, wordLen);
                right += wordLen;

                if(target.find(str) != target.end()) {
                    ++m_map[str];
                    ++count;
                    while(m_map[str] > target[str]) {
                        string temp = s.substr(left, wordLen);
                        left += wordLen;
                        --m_map[temp];
                        --count;
                    }
                    if(count == wordsNum) {
                        ans.push_back(left);
                    }
                } else {
                    left = right;
                    count = 0;
                    m_map.clear();
                }

            }
        }
        return ans;
    }
};


// 用unordered_map 和 unordered_set
class SolutionOlder2 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = s.size();
        int m = words.size();
        int n = words[0].size();
        unordered_set<string> m_set;
        for(int i = 0; i < m; i++) {
            m_set.insert(words[i]);
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int start = i;
            int nextStart = i + m * n;
            unordered_map<string, int> m_map;
            for(int j = 0; j < m; j++) {
                unordered_map<string, int>::iterator it = m_map.find(words[j]);
                it == m_map.end() ? m_map[words[j]] = 1 : (it->second)++;
            }
            for(int j = 0; j < m; j++) {
                rightIn(m_set, m_map, s.substr(j * n + i, n));
            }
            if(m_map.empty()) res.push_back(start);
            while(nextStart + n <= len) {
                leftOut(m_set, m_map, s.substr(start, n));
                rightIn(m_set, m_map, s.substr(nextStart, n));
                start += n;
                nextStart += n;
                if(m_map.empty()) res.push_back(start);
            }
        }
        return res;
    }

    void rightIn(unordered_set<string>& m_set, unordered_map<string, int>& m_map, string str) {
        unordered_map<string, int>::iterator it = m_map.find(str);
        int flag = it != m_map.end(); // 在map中为1
        flag <<= 1;
        flag += m_set.find(str) != m_set.end(); // 在set中为1
        // 四种状态
        // 11 在map中    在set中
        // 10 在map中    不在set中
        // 01 不在map中  在set中
        // 00 不在map中  不在set中
        switch(flag){
            case 0:
                m_map[str] = 1;
                break;
            case 1:
                m_map[str] = -1;
                break;
            case 2:
                (it->second)++;
                break;
            case 3:
                (it->second) == 1 ? m_map.erase(str) : (it->second)--;
                break;
        }

    }

    void leftOut(unordered_set<string>& m_set, unordered_map<string, int>& m_map, string str) {
        unordered_map<string, int>::iterator it = m_map.find(str);
        int flag = it != m_map.end(); // 在map中为1
        flag <<= 1;
        flag += m_set.find(str) != m_set.end(); // 在set中为1
        // 四种状态
        // 11 在map中    在set中
        // 10 在map中    不在set中
        // 01 不在map中  在set中
        // 00 不在map中  不在set中 (这种情况不存在, 进来的时候必定会在map中存在，不可能不存在)
        switch(flag){
            case 1:
                m_map[str] = 1;
                break;
            case 2:
                (it->second) == 1 ? m_map.erase(str) : (it->second)--;
                break;
            case 3:
                (it->second) == -1 ? m_map.erase(str) : (it->second)++;
                break;
        }

    }
};

// 用map、set
class SolutionOlder1 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = s.size();
        int m = words.size();
        int n = words[0].size();
        set<string> m_set;
        for(int i = 0; i < m; i++) {
            m_set.insert(words[i]);
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int start = i;
            int nextStart = i + m * n;
            map<string, int> m_map;
            for(int j = 0; j < m; j++) {
                map<string, int>::iterator it = m_map.find(words[j]);
                it == m_map.end() ? m_map[words[j]] = 1 : (it->second)++;
            }
            for(int j = 0; j < m; j++) {
                rightIn(m_set, m_map, s.substr(j * n + i, n));
            }
            if(m_map.empty()) res.push_back(start);
            while(nextStart + n <= len) {
                leftOut(m_set, m_map, s.substr(start, n));
                rightIn(m_set, m_map, s.substr(nextStart, n));
                start += n;
                nextStart += n;
                if(m_map.empty()) res.push_back(start);
            }
        }
        return res;
    }

    void rightIn(set<string>& m_set, map<string, int>& m_map, string str) {
        map<string, int>::iterator it = m_map.find(str);
        int flag = it != m_map.end(); // 在map中为1
        flag <<= 1;
        flag += m_set.find(str) != m_set.end(); // 在set中为1
        // 四种状态
        // 11 在map中    在set中
        // 10 在map中    不在set中
        // 01 不在map中  在set中
        // 00 不在map中  不在set中
        switch(flag){
            case 0:
                m_map[str] = 1;
                break;
            case 1:
                m_map[str] = -1;
                break;
            case 2:
                (it->second)++;
                break;
            case 3:
                (it->second) == 1 ? m_map.erase(str) : (it->second)--;
                break;
        }

    }

    void leftOut(set<string>& m_set, map<string, int>& m_map, string str) {
        map<string, int>::iterator it = m_map.find(str);
        int flag = it != m_map.end(); // 在map中为1
        flag <<= 1;
        flag += m_set.find(str) != m_set.end(); // 在set中为1
        // 四种状态
        // 11 在map中    在set中
        // 10 在map中    不在set中
        // 01 不在map中  在set中
        // 00 不在map中  不在set中 (这种情况不存在, 进来的时候必定会在map中存在，不可能不存在)
        switch(flag){
            case 1:
                m_map[str] = 1;
                break;
            case 2:
                (it->second) == 1 ? m_map.erase(str) : (it->second)--;
                break;
            case 3:
                (it->second) == -1 ? m_map.erase(str) : (it->second)++;
                break;
        }

    }
};
