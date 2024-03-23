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
        vector<int> v;
        ListNode* temp = head;
        while(temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        int i=0;
        int n=v.size();
        while(temp && temp->next) {
            temp->val = v[i];
            temp->next->val = v[n-1-i];
            i++;
            temp = temp->next->next;
            if(temp && !temp->next) {
                temp->val = v[n/2];
            }
        }
    }
};
