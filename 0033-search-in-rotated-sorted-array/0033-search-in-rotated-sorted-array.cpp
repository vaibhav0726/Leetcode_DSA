class Solution {
private:
    int pivot(vector<int>& nums){
        int low=0, high = nums.size()-1;
        while(low < high){
            int mid= low + (high - low)/2;
            if(nums[mid] < nums[0]){
                high = mid;
            }
            else{
                low = mid +1;
            }
        }
        return low;
    }
    int binary_search(vector<int>& nums, int target, int low, int high){
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int piv = pivot(nums);
        int n = nums.size();
        if(nums[piv] <= target && target <= nums[n-1]){
            return binary_search(nums, target, piv, n-1);
        }
        else{
            return binary_search(nums, target, 0, piv-1);
        }
    }
};