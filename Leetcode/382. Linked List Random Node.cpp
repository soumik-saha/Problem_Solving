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

    int size = 0;
    ListNode *ptr; 
    Solution(ListNode* head) {
        ListNode* temp = head;
        ptr = head;
        while(temp!=NULL) {
            temp = temp->next;
            size++;
        }
    }
    
    
    int getRandom() {
        ListNode *temp = ptr;
        int index = rand()%size;
        for(int i=0; i<index; i++) {
            temp = temp->next;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
