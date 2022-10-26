class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                low = mid +1;
            else
                high = mid-1;
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > target){
                return i;
            }
        }
        return nums.size();
    }
};