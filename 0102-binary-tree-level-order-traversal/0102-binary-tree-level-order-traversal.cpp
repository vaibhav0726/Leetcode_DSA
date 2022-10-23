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
    int giveHeight(TreeNode* temp){
        if(temp == NULL) return 0;
        int lHeight = giveHeight(temp -> left);
        int rHeight = giveHeight(temp -> right);
        if(lHeight > rHeight) return lHeight+1;
        else return rHeight+1;
    }
    
    void solve(vector<int> &v, int i, TreeNode* root){
        if(root == NULL) return;
        if(i==1){
            v.push_back(root->val);
        }
        solve(v, i-1, root -> left);
        solve(v, i-1, root -> right);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        TreeNode* temp = root;
        int height = giveHeight(temp); 
        temp = root;
        for(int i=1; i<=height; i++){
            vector<int> v;
            solve(v, i, temp);
            ans.push_back(v);
        }
        return ans;
    }
};