class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum ^= nums[i];
        }
        return sum;
    }
};