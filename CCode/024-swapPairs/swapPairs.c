//
// Created by shuai on 2023/8/12.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode root;
    root.next = head;
    struct ListNode* p = &root;
    while(p->next && p->next->next) {
        struct ListNode* cur = p;
        p = p->next->next;
        cur->next->next = p->next;
        p->next = cur->next;
        cur->next = p;
        p = cur->next->next;
    }
    return root.next;
}