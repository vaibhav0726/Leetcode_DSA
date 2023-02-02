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
    TreeNode* mi(TreeNode* root){
        if(root -> left == NULL)
            return root;
        else
            return mi(root -> left);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        } 
        if (root -> val > key) {
            root -> left = deleteNode(root -> left, key);
        } else if (root -> val < key) {
            root -> right = deleteNode(root -> right, key);
        } else {
            if (root -> left == NULL && root -> right == NULL) {
                return NULL;
                
            } else if (root -> left == NULL) { // 1 or 0 child
                root = root -> right;
            } else if (root -> right == NULL) { // 1 or 0 child
                root = root -> left;
            } else {
//                 minimum in the right subtreee
                TreeNode* minNode = mi(root -> right);
                root -> val = minNode -> val;
                root -> right = deleteNode(root -> right, minNode -> val);
            }
        }
        return root;
    }
};