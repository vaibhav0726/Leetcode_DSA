class Solution {
    int bfs(vector<vector<pair<int, int>>> &adj, int &n){
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(1);
        int mi = INT_MAX;
        vis[1] = true;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto &i: adj[front]){
                mi = min(mi, i.second);
                if(!vis[i.first]){
                    vis[i.first] = true;
                    q.push(i.first);
                }
            }
        }
        
        return mi;
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto& road: roads){
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        return bfs(adj, n);
    }
};