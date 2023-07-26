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

/*
    输入：l1 = [2,4,3], l2 = [5,6,4]
    输出：[7,0,8]
    解释：342 + 465 = 807.
*/

#include<iostream>
using namespace std;

class ListNode{
public:
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* head = new ListNode(-1,nullptr);
        ListNode* p = head;
        int carry = 0;
        while(p1 || p2 || carry){
            int num1 = p1 ? p1->val : 0;
            int num2 = p2 ? p2->val : 0;
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            ListNode* tmp = new ListNode(sum % 10, nullptr);
            p->next = tmp;
            p = tmp;
            
            if(p1){
                p1 = p1->next;
            }
            if(p2){
                p2 = p2->next;
            };
        }
        p = head->next;
        delete head;
        return p;
    }
};

ListNode* addListNode(ListNode* head, int val){
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->val = val;
    tmp->next = head;
    return tmp;
}

void printListNode(ListNode* head){
    ListNode* dex = head;
    while(dex){
        cout << dex->val;
        dex = dex->next;
        if(dex){
            cout << " --> ";
        }
    }
}

int main(){
    ListNode* L1 = NULL;
    ListNode* L2 = NULL;
    L1 = addListNode(L1, 3); 
    L1 = addListNode(L1, 4);
    L1 = addListNode(L1, 2);
    L2 = addListNode(L2, 4);
    L2 = addListNode(L2, 6);
    L2 = addListNode(L2, 5);
    Solution solution;
    ListNode* result = solution.addTwoNumbers(L1, L2);
    printListNode(result);
    return 0;
}