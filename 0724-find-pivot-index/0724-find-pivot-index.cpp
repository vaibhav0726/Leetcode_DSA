class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i, total=0;
        for(i=0; i<nums.size(); i++){
            total = total + nums[i];
        }
        int sum = 0;
        for(i=0; i<nums.size(); sum += nums[i++]){
            if(sum * 2 == total - nums[i]){
                return i;
            }
        }
        return -1;
    }
};