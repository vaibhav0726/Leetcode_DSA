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
    int solve(TreeNode *root, int sum){
        if(root == NULL) return 0;
        if(root -> left == NULL && root -> right == NULL){
            return sum*10 + root -> val;
        }
        int ls = solve(root -> left, sum*10 + root -> val);
        int rs = solve(root -> right, sum*10 + root -> val);
        return ls + rs;
    }
public:
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};