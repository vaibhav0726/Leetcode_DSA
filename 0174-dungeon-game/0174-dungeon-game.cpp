class Solution {
private: 
    int solve(vector<vector<int>>& dungeon, int cr, int cc, vector<vector<int>> &dp){
        if(cr == dungeon.size() || cc == dungeon[0].size()){
            return INT_MAX;
        }
        if(cr == dungeon.size() -1 && cc == dungeon[0].size()-1){
            return dungeon[cr][cc] > 0 ? 1 : 1-dungeon[cr][cc];
        }
        if(dp[cr][cc] != -1){
            return dp[cr][cc];
        }
        int r = solve(dungeon, cr, cc+1, dp);
        int d = solve(dungeon, cr+1, cc, dp);
        int hp = min(r, d)- dungeon[cr][cc];
        return dp[cr][cc] = hp > 0 ? hp : 1;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon[0].size(), -1));
        return solve(dungeon, 0, 0, dp);
    }
};