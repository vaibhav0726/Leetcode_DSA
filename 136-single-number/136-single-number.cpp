class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum = sum^nums[i];
        }
        return sum;
    }
};