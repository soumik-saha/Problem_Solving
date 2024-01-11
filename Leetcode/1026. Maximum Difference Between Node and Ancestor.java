/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int maxAncestorDiff(TreeNode root) {
        if(root==null)
            return 0;
        
        return solve(root, root.val, root.val);
    }

    private int solve(TreeNode node, int curMax, int curMin) {
        if(node==null)
            return curMax - curMin;

        curMax = Math.max(curMax, node.val);
        curMin = Math.min(curMin, node.val);
        
        int left = solve(node.left, curMax, curMin);
        int right = solve(node.right, curMax, curMin);

        return Math.max(left, right);
    }
}
