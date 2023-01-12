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
    int pathSum_new(TreeNode* root, long long int sum){
        if(root == NULL) return 0;
        long int res = 0;
        if(sum == root -> val){
            res++;
        }
        res += pathSum_new(root -> left, sum - root -> val);
        res += pathSum_new(root -> right, sum - root-> val);
        return res;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return 0;
        }
        return pathSum(root -> left, targetSum) + pathSum_new(root, targetSum) + pathSum(root -> right, targetSum);
    }
};