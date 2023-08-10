
#include<iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* pre = head;
        ListNode* cur = head;
        for(int i = 0; i < n; i++) {
            pre = pre->next;
        }
        if(pre == nullptr) return head->next;
        while(pre->next) {
            pre = pre->next;
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return head;
    }
};