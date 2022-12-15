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
    void reorderList(ListNode* head) {
        int count = 0;
        ListNode *temp = head;
        while (temp != NULL){
            count++;
            temp = temp->next;
        }
        if (head->next == NULL){
            return;
        }
        ListNode *ptr = head;
        ListNode *postptr;
        int times = count/2;
        for (int i=0; i<times; i++){
            postptr = ptr->next;
            ListNode *temp = head;
            int k = 0;
            for (int j=0; j<count-k-1; j++){
                temp = temp->next;
            }
            k++;
            ptr->next = temp;
            ptr = ptr->next;
            ptr->next = postptr;
            ptr = ptr->next;
            
        }
        ptr->next = NULL;
    }
};
