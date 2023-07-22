class Solution {
private:
    int giveMinCoins(vector<int>& coins, int amount, vector<vector<int>> &dp, int n){
        if(amount == 0){
            return 0;
        }
        if(n < 0 || amount < 0){
            return INT_MAX-1;
        }
        if(dp[n][amount] != -1){
            return dp[n][amount];
        }
        int ans = min(1 + giveMinCoins(coins, amount-coins[n], dp, n), giveMinCoins(coins, amount, dp, n-1));
        
        return dp[n][amount] = ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int ans = giveMinCoins(coins, amount, dp, n-1);
        return ans < INT_MAX - 1 ? ans : -1;
    }
};