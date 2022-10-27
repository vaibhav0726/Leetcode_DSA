class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int low=0, high = n-1;
        int i = n-1;
        while(low <= high){
            if(abs(nums[low]) > abs(nums[high])){
                ans[i--] = nums[low] * nums[low];
                low++;
            }
            else{
                ans[i--] = nums[high] * nums[high];
                high--;
            }
        }
        return ans;
    }
};