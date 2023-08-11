
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    while(true) {
        int left = (index << 1) | 1;
        int right = left + 1;
        int temp = (left < heapSize && arr[index]->val > arr[left]->val) ? left : index;
        temp = (right < heapSize && arr[temp]->val > arr[right]->val) ? right : temp;
        if(temp == index) return;
        swap(arr, index, temp);
        index = temp;
    }
}

class Solution {
public:
     ListNode* mergeKLists(vector<ListNode*>& lists) {
        int listsSize = lists.size();
        if(listsSize == 1) return lists[0];
        struct ListNode** arr;
        arr = new struct ListNode*[listsSize + 1];
        int heapSize = 0;
        struct ListNode* head = new struct ListNode();
        struct ListNode* cur = head;

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
            cur->next = nullptr;
        }
        return head->next;
    }
};

int main() {
    vector<struct ListNode*> lists;
    lists.push_back(new struct ListNode(1, nullptr));
    lists.push_back(new struct ListNode(0, nullptr));
    Solution solution;
    solution.mergeKLists(lists);
    return 0;
}





