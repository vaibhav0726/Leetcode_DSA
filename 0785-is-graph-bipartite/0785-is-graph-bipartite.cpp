class Solution {
    bool odd_cycle = false;
    void dfs(vector<vector<int>>& graph, vector<int> &vis, int src, int parent, int color){
        vis[src] = color;
        for(int &i: graph[src]){
            if(vis[i] == 0){
                dfs(graph, vis, i, src, 3-color);
            }
            else if(i != parent && vis[i] == color){
                odd_cycle = true;
            }
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                dfs(graph, vis, i, 0, 1);
                if(odd_cycle){
                    return false;
                }
            }
        }
        return true;
    }
};