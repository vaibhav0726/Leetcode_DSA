class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i=0, numCount = 0;
        while(i<n){
            if(nums[i] != 0){
                swap(nums[i], nums[numCount]);
                numCount++;
            }
            i++;
        }
    }
};