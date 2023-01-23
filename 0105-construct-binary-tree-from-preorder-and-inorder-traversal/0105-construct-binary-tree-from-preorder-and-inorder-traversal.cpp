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
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int inS, int inE, int preS, int preE){
        if(inS > inE) return NULL;
        int rootData = preorder[preS];
        int rootIdx = -1;
        for(int i=inS; i<=inE; i++){
            if(inorder[i] == rootData){
                rootIdx = i;
                break;
            }
        }
        int lInS = inS;
        int lInE = rootIdx - 1;
        int lPreS = preS + 1;
        int lPreE = lInE + lPreS - lInS;
        int rInS = rootIdx + 1;
        int rInE = inE;
        int rPreS = lPreE + 1;
        int rPreE = preE;
        TreeNode* root = new TreeNode(rootData);
        root -> left = buildTreeHelper(preorder, inorder, lInS, lInE, lPreS, lPreE);
        root -> right = buildTreeHelper(preorder, inorder, rInS, rInE, rPreS, rPreE);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return buildTreeHelper(preorder, inorder, 0, n-1, 0, n-1);
    }
};