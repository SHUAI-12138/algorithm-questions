
#include<vector>
#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        map<int, int> m_map;
        int len = nums.size();
        map<int, int>::iterator it;
        for(int i = 0; i < len; i++){
            it = m_map.find(target - nums[i]);
            if(it != m_map.end() && it->second != i){
                ret.push_back(it->second);
                ret.push_back(i);
                break;
            }
            m_map.insert(map<int, int>::value_type(nums[i], i));
        }
        return ret;
    }
};


int main(){
    vector<int> nums1;
    nums1.push_back(2);
    nums1.push_back(7);
    nums1.push_back(11);
    nums1.push_back(15);
    int target = 9;
    Solution solution;
    vector<int> sum;
    sum = solution.twoSum(nums1, target);
    vector<int>::iterator it = sum.begin();
    cout << "[" << *it << ", " ;
    it++;
    cout << *it << "]";
    return 0;
}

