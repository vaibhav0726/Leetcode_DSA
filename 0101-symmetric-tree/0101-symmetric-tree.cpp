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
    bool solve(TreeNode* root, TreeNode* root2){
        if(root == NULL && root2== NULL){
            return true;
        }
        if(root == NULL || root2== NULL){
            return false;
        }
        if(root -> val != root2 -> val){
            return false;
        }
        bool ans1 = solve(root -> left, root2 -> right);
        bool ans2 = solve(root -> right, root2 -> left);
        return ans1  && ans2;
    }
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode *root2 = root;
        return solve(root, root2);
    }
};