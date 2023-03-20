class Solution {
    int dfs(unordered_map<int, list<int>> &adj, vector<int>& quiet, int src, vector<int> &ans){
        if (ans[src] == -1) {
            ans[src] = src;
            for (int &child: adj[src]) {
                int cand = dfs(adj, quiet, child, ans);
                if (quiet[cand] < quiet[ans[src]])
                    ans[src] = cand;
            }
        }
        return ans[src];
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        unordered_map<int, list<int>> adj;
        int n = quiet.size();
        for(int i=0; i<richer.size(); i++){
            int u = richer[i][1];
            int v = richer[i][0];
            adj[u].push_back(v);
        }
        
        vector<int> ans(n, -1);
        for(int i=0; i<n; i++){
            dfs(adj, quiet, i, ans);
        }
        return ans;
    }
};