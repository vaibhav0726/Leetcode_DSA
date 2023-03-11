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
class DiPair{
public:
    bool isBst;
    int sum;
    int ma;
    int mi;
    DiPair(){
        isBst = true;
        sum = 0;
        ma = INT_MIN;
        mi = INT_MAX;
    }
};

class Solution { 
public:
    int sum;
    DiPair solve(TreeNode* root){
        if(root == NULL){
            return DiPair();
        }
        DiPair left = solve(root -> left);
        DiPair right = solve(root -> right);
        DiPair self;
        if(left.isBst && right.isBst && root -> val < right.mi && root -> val > left.ma){
            sum = max(sum, left.sum + right.sum + root -> val);
            self.isBst = true;
            self.sum = left.sum + right.sum + root -> val;
            self.ma = max(root ->val, right.ma);
            self.mi = min(root -> val, left.mi);
            return self;
        }
        else{
            self.isBst = false;
            self.sum = max(left.sum, right.sum);
            sum = max(sum, self.sum);
            return self;
        }
    }
    int maxSumBST(TreeNode* root) {
        sum = 0;
        solve(root);
        return sum;
    }
};