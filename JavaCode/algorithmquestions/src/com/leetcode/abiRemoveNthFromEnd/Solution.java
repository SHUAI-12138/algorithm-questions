package com.leetcode.abiRemoveNthFromEnd;

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
import data.structure.ListNode;
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head.next == null) return null;
        ListNode pre = head;
        ListNode cur = head;
        for(int i = 0; i < n; i++) {
            pre = pre.next;
        }
        if(pre == null) return head.next;
        while(pre.next != null) {
            pre = pre.next;
            cur = cur.next;
        }

        cur.next = cur.next.next;
        return head;
    }
}