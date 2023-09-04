//
// Created by shuai on 2023/9/4.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == nullptr || head->next == nullptr) return head;
        int num = 1;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != nullptr) {
            fast = fast->next;
            if(num > k) slow = slow->next;
            num++;
        }
        if(num > k) {
            ListNode* root = head;
            head = slow->next;
            slow->next = nullptr;
            fast->next = root;
            return head;
        } else {
            k %= num;
            return rotateRight(head, k);
        }
    }
};