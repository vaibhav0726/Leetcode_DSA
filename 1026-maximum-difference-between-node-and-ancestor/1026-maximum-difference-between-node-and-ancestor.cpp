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
    int maxAncestorDiff(TreeNode* root, int mn=1000000, int mx=0) {
        if (!root)
            return mx-mn;
        mn = min(mn, root->val);
        mx = max(mx, root->val);
        
        return max(maxAncestorDiff(root->left,  mn, mx), maxAncestorDiff(root->right, mn, mx));
    }
};