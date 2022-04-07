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
    public TreeNode insertIntoBST(TreeNode root, int key) {
        
        if(root == null){
            TreeNode newNode = new TreeNode(key);
            root = newNode;
            return root;
        }
        
        if(root.val > key)
            root.left = insertIntoBST(root.left,key);
        else if(root.val < key)
            root.right = insertIntoBST(root.right,key);
        return root;
    }
}