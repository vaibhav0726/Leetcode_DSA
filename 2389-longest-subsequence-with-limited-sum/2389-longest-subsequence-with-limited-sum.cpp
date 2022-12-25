class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=1; i<nums.size(); i++){
            nums[i] = nums[i-1] + nums[i];
        }
        for(int i=0; i<queries.size(); i++){
            int idx = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
            ans.push_back(idx);
        }
        return ans;
    }
};