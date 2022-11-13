class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<nums.size()-2; i++){
            if(i == 0 || (i > 0 && nums[i-1] != nums[i])){
                int low = i+1, high = nums.size()-1, sum = 0-nums[i];
                while(low < high){
                    if(nums[low] + nums[high] == sum){
                        ans.push_back({nums[low], nums[i], nums[high]});
                        
                        while(low < high && nums[low+1] == nums[low]) low++;
                        while(low < high && nums[high-1] == nums[high]) high--;
    
                        low++;
                        high--;
                    }
                    else if(nums[low] + nums[high] < sum){
                        low++;
                    }
                    else{
                        high--;
                    }
                }
            }
        }
        return ans;
    }
};