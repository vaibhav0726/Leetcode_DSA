class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0, high = nums.size()-1;
        while(low<high){
            // means it is already sorted
            if(nums[low] < nums[high]){
                return nums[low];
            }
            int mid = low + (high-low)/2;
            if(nums[mid] < nums[low]){
                high = mid;
            }
            else{
                low = mid +1;
            }
        }
        return nums[low];
    }
};