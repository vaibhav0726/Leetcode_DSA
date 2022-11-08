/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    bool getPath(TreeNode* root, TreeNode* p, vector<int> &ans){
        if(root == NULL) return false;
        ans.push_back(root -> val);
        if(root -> val == p -> val) return true;
        if(getPath(root->left, p, ans) || getPath(root->right, p, ans)){
            return true;
        }
        ans.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         naive approach
        vector<int> p1;
        vector<int> p2;
        TreeNode* temp = root;
        getPath(temp, p, p1);
        temp = root;
        getPath(temp, q, p2);
        TreeNode* ans = NULL;
        for(int i=0; i<p1.size() && i<p2.size(); i++){
            if(p1[i] == p2[i]) {
                ans = new TreeNode(p1[i]);
            }
        }
        return ans;
        
        
//         Efficient approach
        
    }  
};