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
    void solve(TreeNode* root, vector<string> &ans, string str){
        if(root != NULL){
            if(root -> left == NULL && root -> right == NULL){
                ans.push_back(str + to_string(root -> val));
                return;
            }
            solve(root -> left , ans, str + to_string(root -> val) + "->");
            solve(root -> right , ans, str + to_string(root -> val) + "->");
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        TreeNode* temp = root;
        vector<string> ans;
        solve(temp, ans, "");
        return ans;
    }
};