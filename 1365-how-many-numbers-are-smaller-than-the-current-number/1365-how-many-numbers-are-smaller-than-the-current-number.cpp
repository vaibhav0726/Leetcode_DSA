class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        vector<int> ans;
        for(int i=0; i<v.size(); i++){
            int idx = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
            ans.push_back(idx);
        }
        return ans;
    }
};