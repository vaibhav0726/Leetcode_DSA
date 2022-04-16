// Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that 
// every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

// time:- O(n) for traversing every node space:- O(n) for recursion stack
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
    
    // iterative approach
    // time:- O(n) space:- O(n)
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL)
            return NULL;
        stack<TreeNode> s;
        TreeNode* node = root;
        while(!s.empty() || node != NULL){
            while(node != NULL){
                s.push(node);
                node = node -> right;
            }
            node = s.pop();
            sum += node -> val;
            node -> val = sum;
            node = node -> left;
        }
        return root;
    }
};
