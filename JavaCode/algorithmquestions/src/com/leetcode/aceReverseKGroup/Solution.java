package com.leetcode.aceReverseKGroup;

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
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode root = new ListNode(-1, head);
        ListNode start = root;
        ListNode end = root;
        while(end != null) {
            end = start;
            for(int i = 0; i < k; i++) {
                if(end.next != null) {
                    end = end.next;
                } else {
                    return root.next;
                }
            }
            start = reversal(start, end);
        }
        return root.next;
    }

    public static ListNode reversal(ListNode start, ListNode end) {
        ListNode ret = start.next;
        ListNode p = ret;
        ListNode head = end.next;
        while(p != end){
            ListNode temp = p.next;
            p.next = head;
            head = p;
            p = temp;
        }
        end.next = head;
        start.next = end;
        return ret;
    }
}
