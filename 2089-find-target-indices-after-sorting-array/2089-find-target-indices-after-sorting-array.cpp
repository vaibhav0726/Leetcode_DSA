class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.size() - 1;
        int left = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                left = mid;
                high = mid -1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        low = 0, high = nums.size() - 1;
        int right = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                right = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        // cout << left << " " << right;
        if(left == -1 || right == -1){
            return {};
        }
        vector<int> ans;
        for(int i=left; i<=right; i++){
            ans.push_back(i);
        }
        return ans;
    }
};