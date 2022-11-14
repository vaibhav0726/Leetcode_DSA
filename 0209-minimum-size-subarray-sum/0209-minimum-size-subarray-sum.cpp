class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=0;
        int sum = 0;
        int n = nums.size(), ans = INT_MAX;
        while(j < n){
            sum += nums[j];
            while(i <= j && sum >= target){
                sum -= nums[i];
                ans = min(ans, j-i+1);
                i++;
            }
            j++;
        }
        (ans == INT_MAX) ? ans = 0 : ans = ans;
        return ans;
    }
};