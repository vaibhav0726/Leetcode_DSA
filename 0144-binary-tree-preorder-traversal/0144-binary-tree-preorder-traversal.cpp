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
    void pre(vector<int> &v, TreeNode* root){
        if(root == NULL) return;
        v.push_back(root->val);
        pre(v, root->left);
        pre(v, root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
//         recursively
        // vector<int> v;
        // pre(v, root);
        // return v;
        
        // iterative solution
        vector<int> v;
        if(root == NULL) return v;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            v.push_back(temp->val);
            if(temp->right != NULL) s.push(temp->right);
            if(temp->left != NULL) s.push(temp->left);
        }
        return v;
    }
};