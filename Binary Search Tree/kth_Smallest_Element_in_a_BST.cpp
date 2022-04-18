// Given the root of a binary search tree, and an integer k, 
// return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

// C++ || 3 approaches || Vector || Inorder || Stack

Time:- O(n)
Space:- O(n)

class Solution {
public:
    vector<int> v;
    void inorder(TreeNode* root){
        if(root != NULL){
            inorder(root -> left);
            v.push_back(root -> val);
            inorder(root -> right);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL)
            return 0;
      
        inorder(root);
        return v[k-1];
    }
};

Efficient solution:-
time:- O(n)
space:- O(h)

class Solution {
    private:
    int res = 0;
public:
    void inorder(TreeNode* root, int &k){
        if(root == NULL)
            return;

        inorder(root -> left, k);
        if(--k == 0)
            res = root -> val;
        inorder(root -> right, k); 
    }
    
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL)
            return 0;
        
        inorder(root, k);
        return res;
    }
};

Using stack data structure:-
time:- O(n)
space: - O(n)

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL)
            return 0;
        
        stack<TreeNode*> s;
        while(true){
            while(root != NULL){
                s.push(root);
                root = root -> left;
            }
            root = s.top();
            s.pop();
            if(--k == 0){
                return root -> val;
            }
            root = root -> right;
        }
        
    }
};
