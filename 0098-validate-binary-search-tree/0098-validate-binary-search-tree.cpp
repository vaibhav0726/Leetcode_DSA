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
    bool validBST(TreeNode* root, long ma, long mi){
        if(root == NULL) return true;
        if(root -> val >= ma || root -> val <= mi) return false;
        bool left = validBST(root -> left, root -> val, mi);
        bool right = validBST(root -> right, ma, root -> val);
        return left && right;
    }
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* temp = root;
        return validBST(temp, LONG_MAX, LONG_MIN);
    }
};