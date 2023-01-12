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
    bool flipEquiv(TreeNode* root, TreeNode* root2) {
        if(root == NULL && root2== NULL){
            return true;
        }
        if(root == NULL || root2== NULL){
            return false;
        }
        if(root -> val != root2 -> val){
            return false;
        }
        bool ans1 = flipEquiv(root -> left, root2 -> right) && flipEquiv(root -> right, root2 -> left);
        bool ans2 = flipEquiv(root -> right, root2 -> right) && flipEquiv(root -> left, root2 -> left);
        return ans1 || ans2;
    }
};