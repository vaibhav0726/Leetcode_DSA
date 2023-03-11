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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> res;
            while(size--){
                TreeNode* front = q.front();
                q.pop();
                res.push_back(front -> val);
                if(front -> left) q.push(front -> left);
                if(front -> right) q.push(front -> right);
            }
            ans.push_back(res[res.size() - 1]);
            res.clear();
        }
        return ans;
    }
};