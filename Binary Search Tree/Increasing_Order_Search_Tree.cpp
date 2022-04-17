// Given the root of a binary search tree, rearrange the tree in in-order so that 
// the leftmost node in the tree is now the root of the tree,
// and every node has no left child and only one right child.

class Solution {
public:
    TreeNode* prev = NULL, *head = NULL;
    
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL)
            return NULL;
        increasingBST(root -> left);
        if(prev){
            root -> left = NULL;
            prev -> right = root;            
        }
        if(head == NULL){
            head = root;
        }
        prev = root;
        increasingBST(root -> right);
        
        return head;
    }
};
