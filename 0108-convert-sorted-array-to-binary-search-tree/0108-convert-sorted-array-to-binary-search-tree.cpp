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
    TreeNode* solve(vector<int> &nums, int fi, int la){
        if(fi>la) return NULL;
        int mid = (la + fi)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = solve(nums, fi, mid-1);
        root -> right = solve(nums, mid+1, la);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = solve(nums, 0, nums.size()-1);
        return root;
    }
};