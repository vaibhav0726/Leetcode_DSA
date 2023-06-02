class Solution {
private:
    void dfs(vector<vector<int>>& adj, int src, int &count, vector<bool> &vis){
        count++;
        vis[src] = true;
        for(auto a: adj[src]){
            if(!vis[a]){
                dfs(adj, a, count, vis);
            }
        }
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            long long int x1 = bombs[i][0];
            long long int y1 = bombs[i][1];
            long long int r1 = bombs[i][2];
            for(int j=0; j<n; j++){
                if(i!=j){
                    long long int x2 = bombs[j][0];
                    long long int y2 = bombs[j][1];
                    long long int r2 = bombs[j][2];
                    long long int sub = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
                    if(sub <= r1*r1){
                        // cout << i << " " << j << endl;
                        adj[i].push_back(j);
                    }
                }
            }
        }
        
        // for(int i=0; i<adj.size(); i++){
        //     for(int j=0; j<adj[i].size(); j++){
        //         cout << adj[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            int count = 0;
            vector<bool> vis(n, false);
            dfs(adj, i, count, vis);
            ans = max(count, ans);
        }
        return ans;
        // 19,999,600,002
        // 10,000,000,00
    }
};