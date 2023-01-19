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
    int ht(TreeNode *root) {
        if (root == NULL) {
            return -1;
        }
        int left = ht(root->left);
        int right = ht(root->right);
        return max(left, right) + 1;
    }   
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        int left = ht(root -> left);
        int right = ht(root -> right);
        
        if(abs(left - right) <= 1){
            return isBalanced(root -> left) && isBalanced(root -> right);
        }
        else{
            return false;
        }
    }
};