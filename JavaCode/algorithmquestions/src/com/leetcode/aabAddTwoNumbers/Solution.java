package com.leetcode.aabAddTwoNumbers;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
/*
 * input: l1 = [2,4,3], l2 = [5,6,4]
 * output: [7,0,8]
 * comment: 342 + 465 = 807.
 */
public class Solution {
    public static void main(String[] args) {
        ListNode l1 = new ListNode(2, null);
        ListNode l2 = new ListNode(5, null);
        l1.pushListNode(l1, 4);
        l1.pushListNode(l1, 3);
        l2.pushListNode(l2, 6);
        l2.pushListNode(l2, 4);
        Solution solution = new Solution();
        ListNode ret = solution.addTwoNumbers(l1, l2);
        ret.printListNode(ret);
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode head = new ListNode(-1, null);
        ListNode p = head;

        while (l1 != null || l2 != null || carry != 0) {
            int num1 = (l1 != null) ? l1.val : 0;
            int num2 = (l2 != null) ? l2.val : 0;
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            ListNode tmp = new ListNode(sum % 10, null);
            p.next = tmp;
            p = tmp;
            if (l1 != null)
                l1 = l1.next;
            if (l2 != null)
                l2 = l2.next;
        }
        return head.next;
    }
}

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }

    public void pushListNode(ListNode head, int val) {
        if (head == null) {
            head = new ListNode(val, null);
            return;
        }
        ListNode p = head;
        while (p.next != null) {
            p = p.next;
        }
        p.next = new ListNode(val, null);
    }

    public void printListNode(ListNode head) {
        ListNode p = head;
        while (true) {
            System.out.print(p.val);
            if (p.next == null) {
                break;
            }
            System.out.print(" --> ");
            p = p.next;
        }
    }
}
