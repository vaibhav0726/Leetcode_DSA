class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i=-1;
        int sum = 0;
        for( i=0; i<nums.size(); i++){
            sum = sum + nums[i];
        }
        int left_sum = 0, right_sum = sum-nums[0];
        if(left_sum == right_sum) return 0;
        for(i=1; i<nums.size(); i++){
            left_sum += nums[i-1];
            right_sum = sum - left_sum -nums[i];
            if(left_sum == right_sum ){
                return i;
            }
        }
        return -1;
    }
};