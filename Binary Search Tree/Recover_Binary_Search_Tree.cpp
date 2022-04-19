// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. 
// Recover the tree without changing its structure

// brute force
// time:- O(n) + O(nlogn) + O(n) = O(2n + nlogn) space:- O(n)
class Solution {
private:
    vector<int> v;
    void arr(TreeNode* root){
        if(root != NULL){
            arr(root -> left);
            v.push_back(root -> val);
            arr(root -> right);
        }
    }
    int i = 0;
    void fix(vector<int> v, TreeNode* root){
        if(i > v.size() || root == NULL){
            return;
        }
        
        fix(v, root -> left);
        if(v[i] != root -> val){
            int temp ;
            swap(v[i], temp);
            root -> val = temp;
        }
        i++;
        fix(v, root -> right);
        
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode* temp = root;
        arr(temp);
        sort(v.begin(), v.end());
        fix(v, root);
        
    }
};

// Efficient one:- (Morris traversal)
// time :- O(n) space:- O(1)
class Solution {
private: 
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last; 
    void inorder(TreeNode* root) {
        if(root == NULL) 
            return; 
        
        inorder(root->left);
        
        if (prev != NULL && (root->val < prev->val))
        {
           
            // If this is first violation, mark these two nodes as
            // 'first' and 'middle'
            if ( first == NULL )
            {
                first = prev;
                middle = root;
            }
 
            // If this is second violation, mark this node as last
            else
                last = root;
        }
 
        // Mark this node as previous
        prev = root;
        inorder(root->right); 
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL; 
        prev = new TreeNode(INT_MIN); 
        inorder(root);
        if(first && last) swap(first->val, last->val); 
        else if(first && middle) swap(first->val, middle->val); 
    }
};
