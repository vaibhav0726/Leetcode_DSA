class Solution {
//     TLE
    // int Robber(vector<int> &nums, int i){
    //     if(i>=nums.size()) return 0;
    //     int rob = nums[i] + Robber(nums, i+2);
    //     int DontRob = Robber(nums, i+1);
    //     return max(rob, DontRob);
    // }
    
    int robberDp(vector<int> &nums, vector<int> &dp, int i){
        if(i>=nums.size()) return 0;
        if(dp[i] != -1){
            return dp[i];
        }
        int rob = nums[i] + robberDp(nums, dp, i+2);
        int DontRob = robberDp(nums, dp, i+1);
        return dp[i] = max(rob, DontRob);
    }
public:
    int rob(vector<int>& nums) {
        // return Robber(nums, 0);
        
//         use DP for efficient approach
        vector<int> dp(nums.size(), -1);
        return robberDp(nums, dp, 0);
        
    }
};