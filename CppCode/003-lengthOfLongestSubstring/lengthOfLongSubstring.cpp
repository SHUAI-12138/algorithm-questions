
#include<iostream>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    // 0ms
    int lengthOfLongestSubstring(string s) {
        int map[128]; // 用来存储子字符串中字符的位置，同时检测是否有重复字符出现
        for(int i = 0; i < 128; i++){ // 将map中的元素置为-1
            map[i] = -1;
        }
        int head = 0; // 用来指向子字符串开始的位置
        int dex = 0;  // 用来指向重复字符的位置
        int num = 0;  // 用来计数
        int longest = 0;
        for(int i = 0; s[i] != '\0'; i++){
            int tmp = map[s[i]];
            if(tmp != -1) {
                dex = tmp; 
                for(; dex >= head; dex--){ // 回溯，删除重复字符之前的字符
                    map[s[dex]] = -1;
                    num--;
                }
                head = tmp + 1;
            } 

            map[s[i]] = i;
            num++;
            //printf("%d\n", num);
            longest = longest < num ? num : longest;
        }
        return longest;
    }

    // 32ms
    int lengthOfLongestSubstring2(string s) {
        map<char, int> m_map;
        map<char, int>::iterator it;
        int head = 0;
        int num = 0;
        int longest = 0;

        for(int i = 0; i < s.length(); i++) {
            it = m_map.find(s[i]);
            if(it != m_map.end()) {
                int tmp = it->second;
                for(int j = tmp; j >= head; j--) {
                    m_map.erase(s[j]);
                    num--;
                }
                head = tmp + 1;
            }
            m_map.insert(map<char, int>::value_type(s[i], i));
            num++;
            longest = longest >= num ? longest : num;
        }
        return longest;
    }
};

int main() {
    string str = "abcabcbb";
    Solution sulotion;
    cout << sulotion.lengthOfLongestSubstring(str);
    return 0;
}