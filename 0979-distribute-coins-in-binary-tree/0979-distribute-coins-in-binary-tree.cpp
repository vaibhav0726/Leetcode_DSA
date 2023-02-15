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
    int moves = 0;
public:
    int distributeCoins(TreeNode* root) {
        help(root);
        return moves;
    }
    int help(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int left = help(root -> left);
        int right = help(root -> right);
        moves += abs(left) + abs(right);
        return left + right + root -> val - 1;
    }
};