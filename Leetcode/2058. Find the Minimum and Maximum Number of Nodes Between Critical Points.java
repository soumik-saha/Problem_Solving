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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        List<Integer> criticalIndices = new ArrayList<>();
        int index = 1;
        ListNode prev = head;
        head = head.next;

        while(head != null && head.next != null) {
            if(head.val>prev.val && head.val>head.next.val) {
                criticalIndices.add(index);
            }
            else if(head.val<prev.val && head.val<head.next.val) {
                criticalIndices.add(index);
            }

            index++;
            prev = head;
            head = head.next;
        }

        int minDist = Integer.MAX_VALUE;
        int maxDist = Integer.MIN_VALUE;

        for(int i=0; i<criticalIndices.size()-1; i++) {
            minDist = Math.min(minDist, criticalIndices.get(i+1)-criticalIndices.get(i));
        }

        if(criticalIndices.size() != 0)
            maxDist = criticalIndices.get(criticalIndices.size()-1) - criticalIndices.get(0);

        int[] result = new int[2];
        result[0] = (minDist==Integer.MAX_VALUE || minDist==0) ? -1 : minDist;
        result[1] = (maxDist==Integer.MIN_VALUE || maxDist==0) ? -1 : maxDist;

        return result;
    }
}
