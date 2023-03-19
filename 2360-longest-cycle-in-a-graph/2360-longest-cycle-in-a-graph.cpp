class Solution {
    int ma = -1;
    void dfs(vector<int>& edges, int src, vector<bool> &vis, vector<int> &dis, int distance, vector<bool> &recursionStack){
        if(src != -1){
            if(!vis[src]){
                vis[src] = true;
                recursionStack[src] = true;
                dis[src] = distance;
                dfs(edges, edges[src], vis, dis, distance + 1, recursionStack);
            }
            else if(recursionStack[src]){
                ma = max(ma, distance - dis[src]);
            }
            
            recursionStack[src] = false;
        }
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> dis(n, 0);
        vector<bool> vis(n, false), recursionStack(n, false);
        
        for(int i=0; i<n; i++){
            if(!vis[i])
                dfs(edges, i, vis, dis, 0, recursionStack);
        }
        
        return ma;
    }
};