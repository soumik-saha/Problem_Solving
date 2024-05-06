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
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* temp = head;
        while(temp) {
            nodes.push_back(temp);
            temp = temp->next;
        }

        int currMax = nodes.back()->val;

        for(int i=nodes.size()-2; i>=0; i--) {
            if(nodes[i]->val<currMax) {
                nodes[i] = NULL;
            }
            else {
                currMax = max(currMax, nodes[i]->val); 
            }
        }

        head = NULL;
        temp = NULL;

        for(auto it:nodes) {
            if(it) {
                if(!head) {
                    head = it;
                    temp = head;
                }
                else {
                    temp->next = it;
                    temp = temp->next;
                }
            }
        }

        return head;
    }
};
