class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if(n <= 0){
            return ans;
        }
        if(n == 1){
            return vector<int>(1, 0); // returning with 1 size and 0 value;
//             same as ans.push_back(0); return ans;
        }
        unordered_map<int, list<int>> adj;
        vector<int> degrees(n, 0);
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degrees[edges[i][0]]++;
            degrees[edges[i][1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++){
            if(degrees[i] == 1){
                q.push(i);
            }
        }
        while(n>2){
            int size = q.size();
            n -= size;
            while(size--){
                int front = q.front();
                q.pop();
                degrees[front]--;
                for(int &i: adj[front]){
                    degrees[i]--;
                    if(degrees[i] == 1){
                        q.push(i);
                    }
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};