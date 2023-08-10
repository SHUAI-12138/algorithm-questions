package com.leetcode.acaMergeTwoLists;

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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode head = new ListNode(-1,null);
        ListNode p = head;
        while(list1 != null && list2 != null) {
            if(list1.val <= list2.val) {
                p.next = list1;
                p = list1;
                list1 = list1.next;
            } else {
                p.next = list2;
                p = list2;
                list2 = list2.next;
            }
        }

        p.next = (list1 == null) ? list2 : list1;

        return head.next;
    }
}
