
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(!list1) return list2;
    if(!list2) return list1;
    struct ListNode head;
    head.next = NULL;
    struct ListNode* p = &head;
    p->next = NULL;
    while(list1 && list2) {
        if(list1->val <= list2->val) {
            p->next = list1;
            p = list1;
            list1 = list1->next;
            continue;
        } else {
            p->next = list2;
            p = list2;
            list2 = list2->next;
            continue;
        }
    }
    p->next = list1 ? list1 : list2;
    return head.next;
}