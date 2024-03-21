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
    ListNode* reverseList(ListNode* head) {
        vector<int> v;
        while(head) {
            v.push_back(head->val);
            head = head->next;
        }
        reverse(v.begin(), v.end());
        ListNode* last;
        for(auto it:v) {
            ListNode* newNode = new ListNode(it);
            if(!head) {
                head = newNode;
            }
            else {
                last->next = newNode;
            }
            last = newNode;
        }
        return head;
    }
};
