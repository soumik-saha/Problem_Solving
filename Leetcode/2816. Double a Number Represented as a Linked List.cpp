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
    ListNode* doubleIt(ListNode* head) {
        string str;
        while (head) {
            str += to_string(head->val);
            head = head->next;
        }

        int carry = 0;
        reverse(str.begin(), str.end());
        for (int i = 0; i < str.size(); i++) {
            int val = (str[i] - '0') * 2 + carry;
            str[i] = '0' + (val % 10);
            carry = val / 10;
        }

        if (carry != 0) {
            str += (carry + '0');
        }

        reverse(str.begin(), str.end());

        head = NULL;
        ListNode* temp = NULL;
        for (char c : str) {
            if (!head) {
                head = new ListNode(c - '0');
                temp = head;
            } else {
                temp->next = new ListNode(c - '0');
                temp = temp->next;
            }
        }

        return head;
    }
};
