/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetricNew(TreeNode* root, TreeNode* root2){
        if(root == NULL && root2 == NULL) return true;
        if(root == NULL && root2 != NULL || root != NULL && root2 == NULL) return false;
        if(root -> val != root2 -> val) return false;
        bool left = isSymmetricNew(root -> left, root2 -> right);
        bool right = isSymmetricNew(root -> right, root2 -> left);
        return left && right;
        
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetricNew(root, root);
    }
};