class Solution {
private:
    void dfs(vector<vector<int>>& isConnected, int src, vector<bool>& vis){
        vis[src] = true;
        for(int i=0; i<isConnected.size(); i++){
            if(isConnected[src][i] && !vis[i]){
                dfs(isConnected, i, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int noOfComponents = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                noOfComponents++;
                dfs(isConnected, i, vis);
            }
        }
        
        return noOfComponents;
    }
};