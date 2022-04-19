// Given the root of a binary tree, flatten the tree into a "linked list":

// used morris traversal here 
// so time:- O(n) space:- O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr -> left){
                TreeNode* pred = curr -> left;
                while(pred -> right != NULL) 
                    pred = pred -> right; 
                
                pred -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = NULL;
            }
            curr = curr -> right;
        }
    }
};
