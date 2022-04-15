// Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. 
// Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). 
// It can be proven that there is a unique answer.

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL)
            return NULL;
        if(root -> val <= high && root -> val >= low){ 
            root -> left = trimBST(root -> left, low, high);
            root -> right = trimBST(root -> right, low, high);
        }
        else{
            if(root -> val < low){
                root = trimBST(root -> right, low, high);
            }
            else if(root -> val > high){
                root = trimBST(root ->left, low, high);
            }
        }
        
        return root;
        
        
    }
};