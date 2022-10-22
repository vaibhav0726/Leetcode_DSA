class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = prices[0], ma = prices[0];
        int ans = INT_MIN;
        for(int i=0; i<prices.size(); i++){
            if(prices[i] < mi){
                ans = max(ans, ma - mi);
                mi = prices[i];
                ma = prices[i];
            }
            else if(prices[i] > ma){
                ma = prices[i];
            }
        }
        // cout<<ma<<mi;
        ans = max(ans, ma - mi);
        return ans;
    }
};