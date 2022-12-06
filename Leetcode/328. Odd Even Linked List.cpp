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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> v;
        ListNode* ptr = head;
        int i=1;
        while(ptr!=NULL){
            if(i%2!=0){
                v.emplace_back(ptr->val);
            }
            i++;
            ptr=ptr->next;
        }
        ptr = head;
        i=1;
        while(ptr!=NULL){
            if(i%2==0){
                v.emplace_back(ptr->val);
            } 
            i++;
            ptr=ptr->next;
        }
        ptr = head;
        i=0;
        while(ptr!=NULL){
            ptr->val = v[i];
            i++;
            ptr=ptr->next;
        }
        return head;
    }
};
