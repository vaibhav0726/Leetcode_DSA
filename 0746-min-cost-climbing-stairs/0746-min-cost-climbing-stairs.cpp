class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[1002] = {0};
        int n = cost.size();
        cout<<n;
        for(int i=n-1; i>=0; i--){
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }
        return min(dp[0], dp[1]);
    }
};