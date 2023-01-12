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
    void solve(TreeNode* root, int &ans, string str){
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL){
            ans += stoi(str + to_string(root -> val), 0, 2);
            return;
        }
        solve(root -> left, ans, str + to_string(root -> val));
        solve(root -> right, ans, str + to_string(root -> val));
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        solve(root, ans, "");
        return ans;
    }
};