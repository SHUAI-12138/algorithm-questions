//
// Created by shuai on 2023/9/4.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

struct ListNode* rotateRight(struct ListNode* head, int k){
    if(k == 0 || head == NULL || head->next == NULL) return head;
    int num = 1;
    ListNode* fast = head;
    ListNode* slow = head;
    while(num <= k && fast->next != NULL) {
        fast = fast->next;
        num++;
    }
    while(fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    if(num > k) {
        ListNode* root = head;
        head = slow->next;
        slow->next = NULL;
        fast->next = root;
        return head;
    } else {
        k %= num;
        return rotateRight(head, k);
    }
}