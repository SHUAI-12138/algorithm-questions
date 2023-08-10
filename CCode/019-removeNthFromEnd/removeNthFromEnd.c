
struct ListNode{
    int val;
    struct ListNode* next;
};

#include<stdlib.h>
#include<stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head == NULL || head->next == NULL) return NULL;
    struct ListNode* pre = 0;
    struct ListNode* cur = 0;
    for(int i = 0; i < n; i++) {
        pre = pre->next;
    }
    if(pre == NULL) return head->next;
    while(pre->next) {
        pre = pre->next;
        cur = cur->next;
    }
    cur->next = cur->next->next;
    return cur;
}