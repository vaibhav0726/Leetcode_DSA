/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void solve(vector<int> &v, Node* root){
        if(root == NULL) return;
        for(Node* n: root->children){
            v.push_back(n->val);
            solve(v, n);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> v;
        if(root == NULL) return v;
        Node* temp = root;
        v.push_back(root->val);
        solve(v, temp);
        return v;
    }
};