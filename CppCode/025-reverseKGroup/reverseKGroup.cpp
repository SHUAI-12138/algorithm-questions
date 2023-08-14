//
// Created by shuai on 2023/8/14.
//

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k <= 1) return head;
        ListNode* root = new ListNode(-1, head);
        ListNode* start = root;
        ListNode* end = start;
        while(end) {
            end = start;
            for(int i = 0; i < k; i++) {
                if(end->next) {
                    end = end->next;
                } else {
                    return root->next;
                }
            }
            start = reversal(start, end);
        }
        return root->next;
    }

    static ListNode* reversal(ListNode* start, ListNode* end) {
        ListNode* ret = start->next;
        ListNode* head = end->next;
        ListNode* p = ret;
        while(p != end) {
            ListNode* temp = p->next;
            p->next = head;
            head = p;
            p = temp;
        }
        end->next = head;
        start->next = end;
        return ret;
    }
};