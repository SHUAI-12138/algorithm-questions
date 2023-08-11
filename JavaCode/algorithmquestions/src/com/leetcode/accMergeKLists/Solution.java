package com.leetcode.accMergeKLists;

import data.structure.ListNode;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */



class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int listsSize = lists.length;
        if(listsSize < 1) return lists[0];
        ListNode[] heap = new ListNode[listsSize];
        ListNode head = new ListNode(-1, null);
        ListNode cur = head;
        int heapSize = 0;

        for(int i = 0; i < listsSize; i++) {
            if(lists[i] != null) {
                Heap.heapPush(heap, heapSize++, lists[i]);
            }
        }

        while(heapSize != 0) {
            cur.next = heap[0];
            cur = heap[0];
            if(heap[0].next != null) {
                heap[0] = heap[0].next;
            } else {
                heap[0] = heap[--heapSize];
            }
            Heap.heapify(heap, 0, heapSize);
            cur.next = null;
        }

        return head.next;
    }
}

class Heap {
    public static void heapPush(ListNode[] arr, int index, ListNode element) {
        arr[index] = element;
        if(index == 0) return;
        while(arr[index].val < arr[(index - 1) >> 1].val) {
            swap(arr, index, (index - 1) >> 1);
            index = (index - 1) >> 1;
            if(index == 0) return;
        }
    }

    public static void heapify(ListNode[] arr, int index, int heapSize) {
        if(((index << 1) | 1) >= heapSize) return;
        while(true) {
            int left = (index << 1) | 1;
            int right = left + 1;
            int temp = (left < heapSize && arr[index].val > arr[left].val) ? left : index;
            temp = (right < heapSize && arr[temp].val > arr[right].val) ? right : temp;
            if(index == temp) return;
            swap(arr, index, temp);
            index = temp;
        }
    }

    public static void swap(ListNode[] arr, int e1, int e2) {
        if(e2 == e1) return;
        ListNode temp = arr[e1];
        arr[e1] = arr[e2];
        arr[e2] = temp;
    }
}