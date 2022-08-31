class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n);
        vector<int> left(n);
        left[0] =1;
        for(int i=1; i<n; i++){
            left[i] = nums[i-1] * left[i-1];
        }
        right[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            right[i] = nums[i+1] * right[i+1];
        }
        for(int i=0; i<n; i++){
            nums[i] = right[i]*left[i];
        }
        return nums;
    }
};