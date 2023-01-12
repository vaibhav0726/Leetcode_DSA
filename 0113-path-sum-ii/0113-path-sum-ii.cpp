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
    bool hasPathSum(TreeNode* root, vector<vector<int>> &lst, int targetSum, vector<int> v) {
        if(root == NULL){
            return false;
        }
        if(root->left == NULL && root ->right == NULL){
            v.push_back(root -> val);
            if(root -> val - targetSum == 0)
                lst.push_back(v);
            return root -> val - targetSum == 0;
        }
        v.push_back(root -> val);
        bool ans1 = hasPathSum(root->left, lst, targetSum - root->val, v);
        bool ans2 = hasPathSum(root->right, lst, targetSum - root->val, v);
        v.pop_back();
        return ans1 || ans2;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> lst;
        vector<int> v;
        hasPathSum(root, lst, targetSum, v);
        return lst;
    }
};