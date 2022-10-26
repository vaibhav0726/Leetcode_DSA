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
private:
    bool solve(TreeNode* root, long ma, long mi){
        if(root == NULL) return true;
        if(root -> val <= mi || root -> val >= ma) return false;
        return solve(root -> left, root->val, mi) && solve(root->right, ma, root->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* temp = root;
        return solve(temp, LONG_MAX, LONG_MIN);
    }
};