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
    int giveLeftMax(TreeNode* root){
        if(root == NULL) return INT_MIN;
        int ma = giveLeftMax(root -> right);
        return max(ma, root -> val);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root -> val < key){
            root -> right = deleteNode(root -> right, key);
        }
        else if(root -> val > key){
            root -> left = deleteNode(root -> left, key);
        }
        else{
//             1 or 0 child
            if(root -> left == NULL)
                return root -> right;
            else if(root -> right == NULL)
                return root -> left;
            else{
//                 for both child
                int lmax = giveLeftMax(root -> left);
                root -> left = deleteNode(root -> left, lmax);
                root -> val = lmax;
            }
        }
        return root;
    }
};