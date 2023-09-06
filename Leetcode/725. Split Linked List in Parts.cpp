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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int n = 0;
        while(temp) {
            n++;
            temp = temp->next;
        }
        vector<ListNode*> ans(k);
        temp = head;
        if(n<=k) {
            for(int i=0; i<n; i++) {
                ans[i] = temp;
                temp = temp->next; 
                ans[i]->next = NULL;
            }
        }
        else {
            int extra = n%k, size = n/k;
            for(int i=0; i<k; i++) {
                ans[i] = temp;
                ListNode* node;
                for(int l=0; l<size; l++) {
                    if(size-1>=0 && l==size-1) {
                        node = temp;
                    }
                    temp = temp->next;
                }
                if(extra) {
                    node = temp;
                    temp = temp->next;
                    extra--;
                }
                node->next = NULL;
            }
        }
        return ans;
    }
};
