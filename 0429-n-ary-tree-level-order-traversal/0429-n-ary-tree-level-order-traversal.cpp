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
public:
    vector<vector<int>> levelOrder (Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
        vector<int> level;
        level.push_back(q.front() -> val);
        ans.push_back(level);
        while(!q.empty()){
            int size = q.size();
            level.clear();
            while(size--){
                Node* front = q.front();
                q.pop();
                for(auto &i: front -> children){
                    level.push_back(i -> val);
                    q.push(i);
                }
            }
            if(level.size() != 0)
                ans.push_back(level);
        }
        
        return ans;
    }
};