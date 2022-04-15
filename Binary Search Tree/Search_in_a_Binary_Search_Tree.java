// You are given the root of a binary search tree (BST) and an integer val.
// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

class Solution {
    public TreeNode searchBST(TreeNode root, int key) {
        if(root == null)
            return root;
        if(root.val==key)
            return root;
        else if(root.val < key)
        {  
            return searchBST(root.right,key);
        }
        else{
            return searchBST(root.left,key);
        }
    }
}
