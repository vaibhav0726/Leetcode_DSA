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
    int max_depth = -1;
public:
    void solve(TreeNode* root, vector<int>& ans, int curr_lev){
        if(root == NULL) return;
        if(curr_lev > max_depth){
            ans.push_back(root -> val);
            max_depth = curr_lev;
        }
        solve(root -> right, ans, curr_lev + 1);
        solve(root -> left, ans, curr_lev + 1);

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};