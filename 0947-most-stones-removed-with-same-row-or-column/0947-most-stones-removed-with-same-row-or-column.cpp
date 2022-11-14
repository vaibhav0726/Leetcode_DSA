class Solution {
private:
    int dfs(vector<vector<int>> &stones, vector<bool> &vis, int idx, int n){
        vis[idx] = true;
        int res = 0;
        for(int i=0; i<n; i++){
            if(!vis[i] && (stones[i][0] == stones[idx][0] || stones[i][1] == stones[idx][1])){
                res += dfs(stones, vis, i, n) + 1;
            }
        }
        return res;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int ans = 0;
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans += dfs(stones, vis, i, n);
            }
        }
        return ans;
    }
};