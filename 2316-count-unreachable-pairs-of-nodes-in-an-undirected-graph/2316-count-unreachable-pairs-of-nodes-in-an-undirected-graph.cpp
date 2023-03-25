class Solution {
    void dfs(unordered_map<int, list<int>> &adj, int src, vector<bool> &vis, long long int &count){
        vis[src] = true;
        count++;
        for(int &i: adj[src]){
            if(!vis[i]){
                dfs(adj, i, vis, count);
            }
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n, false);
        long long numberOfPairs = 0;
        long long sizeOfComponent = 0;
        long long remainingNodes = n;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                sizeOfComponent = 0;
                dfs(adj, i, vis, sizeOfComponent);
                numberOfPairs += sizeOfComponent *(remainingNodes - sizeOfComponent);
                remainingNodes -= sizeOfComponent;
            }
        }
        return numberOfPairs;
    }
};