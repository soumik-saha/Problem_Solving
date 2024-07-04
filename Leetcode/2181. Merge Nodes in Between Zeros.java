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
    public ListNode mergeNodes(ListNode head) {
        ListNode ptr = new ListNode(-1);
        ListNode ref_ptr = ptr;
        ListNode temp = head;

        while(temp!=null && temp.next!=null) {
            if(temp.val==0) {
                ListNode node = new ListNode(0);
                ptr.next = node;
                ptr = ptr.next;
            }
            else {
                ptr.val += temp.val;
            }
            temp = temp.next;
        }

        return ref_ptr.next;
    }
}
