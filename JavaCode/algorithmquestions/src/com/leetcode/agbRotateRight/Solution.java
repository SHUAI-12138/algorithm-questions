package com.leetcode.agbRotateRight;

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
    public ListNode rotateRight(ListNode head, int k) {
        if(k == 0 || head == null || head.next == null) return head;
        ListNode fast = head;
        ListNode slow = head;
        int num = 1;
        while(fast.next != null) {
            fast = fast.next;
            if(num > k) slow = slow.next;
            num++;
        }
        if(num > k) {
            ListNode root = head;
            head = slow.next;
            slow.next = null;
            fast.next = root;
            return head;
        }
        k %= num;
        return rotateRight(head, k);
    }
}
