package com.leetcode.acdSwapPairs;

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
    public ListNode swapPairs(ListNode head) {
        ListNode root = new ListNode(-1, head);
        ListNode cur = root;
        ListNode p = root;
        while(p.next != null && p.next.next != null) {
            p = p.next.next;
            cur.next.next = p.next;
            p.next = cur.next;
            cur.next = p;
            p = p.next;
            cur = p;
        }

        return root.next;
    }
}