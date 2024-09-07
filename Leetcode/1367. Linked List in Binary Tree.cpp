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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root)
            return false;
        return solve(head, root) || isSubPath(head, root->left) ||
               isSubPath(head, root->right);
    }
    bool solve(ListNode* head, TreeNode* root) {
        if (!head)
            return true;
        if (!root)
            return false;

        if (head->val == root->val) {
            return solve(head->next, root->left) ||
                   solve(head->next, root->right);
        }

        return false;
    }
};
