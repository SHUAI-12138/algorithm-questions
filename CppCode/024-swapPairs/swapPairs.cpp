//
// Created by shuai on 2023/8/12.
//

#include<iostream>

using namespace std;

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

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
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
};