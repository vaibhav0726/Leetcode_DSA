class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int j = 0, prod = 1;
        int i = 0, ans = 0;
        while(j < nums.size()){
            prod = prod * nums[j];
            while(i <= j && prod >= k){
                prod = prod / nums[i];
                i++;
            }
            ans = ans + (j - i + 1);
            j++;
        }
        return ans;
    }
};