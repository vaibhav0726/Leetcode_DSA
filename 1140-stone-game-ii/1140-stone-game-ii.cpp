class Solution {
public:
    int dp[100][100];
    int solve(int i, int M, vector<int> &p){
        if(i>=p.size()){
            return 0;
        }
        if(dp[i][M] != -1){
            return dp[i][M];
        }
        
        int total = 0;
        int ans = INT_MIN;
        for(int j=0; j<2*M; j++){
            if(i+j<p.size()){
                total += p[i+j];
            }
            ans = max(ans, total - solve(i+j+1, max(M, j+1), p));
        }
        
        return dp[i][M] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int sum = 0;
        memset(dp, -1, sizeof dp);
        for(auto p: piles){
            sum += p;
        }
        int diff = solve(0, 1, piles);
        
        return (sum + diff)/2;
    }
};