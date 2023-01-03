class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mx = INT_MIN;
        for(int i=0; i<accounts.size(); i++){
            int ans = accumulate(accounts[i].begin(), accounts[i].end(), 0);
            mx = ans > mx ? ans : mx;
        }
        return mx;
    }
};