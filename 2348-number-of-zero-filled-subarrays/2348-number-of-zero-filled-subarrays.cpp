class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int count = 0;
        int n = nums.size(), j = -1;
        for(int i=0;i<n;i++) {
            if(nums[i] != 0) j=i;
            else {
                count += i-j;
            }
        }
        return count;
    }
};