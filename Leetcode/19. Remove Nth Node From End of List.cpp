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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;

        int size = 0; 
        while(curr) {
            curr = curr->next;
            size++;
        }

        if(size==1) {
            return NULL;
        }

        if(size==n) {
            head = head->next;
            return head;
        }

        curr = head;
        for(int i=1; i<=size-n-1; i++) {
            curr = curr->next;
        }

        if(curr->next) {
            curr->next = curr->next->next;
        }

        return head; 
    }
};
