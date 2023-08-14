//
// Created by shuai on 2023/8/14.
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


struct ListNode* reversal(struct ListNode* start, struct ListNode* end) {
    struct ListNode* ret = start->next;
    struct ListNode* head = end->next;
    struct ListNode* p = ret;
    struct ListNode* temp;
    while(p != end) {
        temp = p->next;
        p->next = head;
        head = p;
        p = temp;
    }
    p->next = head;
    start->next = p;
    return ret;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if(!head || k <= 1) return head;
    struct ListNode root;
    root.next = head;
    struct ListNode* start = &root;
    struct ListNode* end = start;
    while(end) {
        for(int i = 0; i < k; i++) {
            if(end->next) {
                end = end->next;
            } else {
                return root.next;
            }
        }
        start = reversal(start, end);
        end = start;
    }
    return root.next;
}