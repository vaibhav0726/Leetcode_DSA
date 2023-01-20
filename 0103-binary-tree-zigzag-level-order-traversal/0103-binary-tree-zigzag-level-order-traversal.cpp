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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode *> st;
        stack<TreeNode *> st2;
        vector<vector<int>> ans;
        if(root){
            st.push(root);
            ans.push_back({root -> val});
        }
        while(!st.empty() || !st2.empty()){
            vector<int> v;
            if(!st.empty()){
                while(!st.empty()){
                    TreeNode *top = st.top();
                    st.pop();
                    if(top -> right){
                        v.push_back( top -> right -> val);
                        st2.push(top -> right);
                    }
                    if(top -> left){
                        v.push_back( top -> left -> val);
                        st2.push(top -> left);
                    }
                }
                if(!v.empty())
                    ans.push_back(v);
            }
            else{
                v.clear();
                while(!st2.empty()){
                    TreeNode *top = st2.top();
                    st2.pop();
                    if(top -> left){
                        v.push_back( top -> left -> val);
                        st.push(top -> left);
                    }
                    if(top -> right){
                        v.push_back( top -> right -> val);
                        st.push(top -> right);
                    }
                }
                if(!v.empty())
                    ans.push_back(v);
            }
        }
        return ans;
    }
};