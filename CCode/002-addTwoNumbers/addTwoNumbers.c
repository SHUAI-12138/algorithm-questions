
/*
    输入：l1 = [2,4,3], l2 = [5,6,4]
    输出：[7,0,8]
    解释：342 + 465 = 807.
*/


#include<stdlib.h>
#include<stdio.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    ListNode* p = head;
    int carry = 0;
    
    while(l1 || l2 || carry){
        int num1 = l1 ? l1->val : 0;
        int num2 = l2 ? l2->val : 0;
        int sum = num1 + num2 + carry;
        carry = sum / 10;
        p->next = (ListNode*)malloc(sizeof(ListNode));
        p = p->next;
        p->next = NULL;
        p->val = sum % 10;
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    p = head->next;
    free(head);
    return p;
}

ListNode* addListNode(ListNode* head, int val){
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->val = val;
    tmp->next = head;
    return tmp;
}

void printListNode(ListNode* head){
    ListNode* dex = head;
    while(dex){
        printf("%d", dex->val);
        dex = dex->next;
        if(dex){
            printf(" --> ");
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
    ListNode* result = addTwoNumbers(L1, L2);
    printListNode(result);
    return 0;
}