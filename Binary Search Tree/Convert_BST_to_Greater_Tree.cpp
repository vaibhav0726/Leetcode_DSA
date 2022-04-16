// Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that 
// every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(root != NULL)
        {
            convertBST(root -> right);
            sum += root -> val;
            root -> val = sum;
            convertBST(root -> left);
        }
        return root;
    }
};
