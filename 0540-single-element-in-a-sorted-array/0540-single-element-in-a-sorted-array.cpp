class Solution {
    int solve(vector<int>& nums, int low, int high){
        if(low>high){
            return 0;
        }
        int mid = low + (high - low)/2;
        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1] ){
            return nums[mid];
        }
        else{
            int lower = solve(nums, low, mid-1);
            int higher = solve(nums, mid+1, high);
            if(lower != 0) return lower;
            else if(higher != 0) return higher;
            else return 0;
        }       
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int ans = solve(nums, 1, nums.size()-2);
        if(ans != 0){
            return ans;
        }
        else{
            if(nums[0] != nums[1] ){
                return nums[0];
            }
            else{
                return nums[nums.size() -1];
            }
        }
    }
};