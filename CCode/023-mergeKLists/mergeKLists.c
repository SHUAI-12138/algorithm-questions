
#include<stdlib.h>
#include<stdio.h>

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

// 交换两个元素在 指针数组 中的位置
void swap(struct ListNode** arr, int e1, int e2) {
    if(e1 == e2) return;
    struct ListNode* temp = arr[e1];
    arr[e1] = arr[e2];
    arr[e2] = temp;
}

// 在 index 处插入元素，向上比对，如果小于父结点，向上调整
void heapPush(struct ListNode** arr, int index, struct ListNode* element) {
    arr[index] = element;
    if(index == 0) return;
    while(arr[index]->val < arr[(index - 1) >> 1]->val) {
        swap(arr, index, (index - 1) >> 1);
        index = (index - 1) >> 1;
        if(index == 0) return;
    }
}

// 弹出根结点之后，将末尾或新元素放入根节点中，向下调整
void heapify(struct ListNode** arr, int index, int heapSize) {
    if(((index << 1) | 1) >= heapSize) return;
    while(1) {
        int left = (index << 1) | 1;
        int right = left + 1;
        int temp = (left < heapSize && arr[index]->val > arr[left]->val) ? left : index;
        temp = (right < heapSize && arr[temp]->val > arr[right]->val) ? right : temp;
        if(temp == index) return;
        swap(arr, index, temp);
        index = temp;
    }
}



struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(lists == NULL) return NULL;
    if(listsSize == 1) return lists[0];
    struct ListNode** arr = (struct ListNode**) malloc(sizeof(struct ListNode*) * (listsSize + 1));
    int heapSize = 0;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = head;
    cur->next = NULL;

    for(int i = 0; i < listsSize; i++) {
        if(lists[i]) {
            heapPush(arr, heapSize++, lists[i]);
        }
    }

    while(heapSize) {
        cur->next = arr[0];
        cur = arr[0];
        if(cur->next) {
            arr[0] = arr[0]->next;
        } else {
            arr[0] = arr[--heapSize];
        }
        heapify(arr, 0, heapSize);
        cur->next = NULL;
    }
    free(arr);
    return head->next;
}

int main() {
    struct ListNode* lists[2];
    lists[0] = (struct ListNode*)malloc(sizeof(struct ListNode));
    lists[0]->next = NULL;
    lists[0]->val = 1;
    lists[1] = (struct ListNode*)malloc(sizeof(struct ListNode));
    lists[1]->next = NULL;
    lists[1]->val = 0;
    mergeKLists(lists, 2);
    return 0;
}














