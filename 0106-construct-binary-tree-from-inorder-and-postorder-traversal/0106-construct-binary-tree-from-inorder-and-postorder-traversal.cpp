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
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inS, int inE, int &postIdx){
        if(inS>inE) return NULL;
        TreeNode* root = new TreeNode(postorder[postIdx--]);
        int inIdx = find(begin(inorder), end(inorder), root -> val) - begin(inorder);
        root -> right = buildTreeHelper(inorder, postorder, inIdx + 1, inE, postIdx);
        root -> left = buildTreeHelper(inorder, postorder, inS, inIdx - 1, postIdx);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(), postIdx = n - 1;
        return buildTreeHelper(inorder, postorder, 0, n - 1, postIdx);
    }
};