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
    public TreeNode balanceBST(TreeNode root) {
        ArrayList<Integer> nodes = new ArrayList<>();
        inorderTraversal(root, nodes);

        return buildBalancedBST(nodes, 0, nodes.size()-1);
    }
    private void inorderTraversal(TreeNode root, ArrayList<Integer> nodes) {
        if(root==null)  return;

        inorderTraversal(root.left, nodes);
        nodes.add(root.val);
        inorderTraversal(root.right, nodes);
    }
    private TreeNode buildBalancedBST(ArrayList<Integer> nodes, int start, int end) {
        if(start>end) {
            return null;
        }

        int mid = (start+end)/2;
        TreeNode node = new TreeNode(nodes.get(mid));

        node.left = buildBalancedBST(nodes, start, mid-1);
        node.right = buildBalancedBST(nodes, mid+1, end);

        return node;
    }
}
