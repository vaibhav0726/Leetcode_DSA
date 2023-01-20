class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> one;
        find(0,nums,one,res);
        return res;
    }
    void find(int p, vector<int>& nums, vector<int>& one, vector<vector<int>>& res) {
        int n = nums.size();
        if(one.size()>1) res.push_back(one);
        unordered_set<int> ht;
        for(int i=p;i<n;i++) {
            if((!one.empty() && nums[i] < one.back()) || ht.count(nums[i])) continue;
            ht.insert(nums[i]);
            one.push_back(nums[i]);
            find(i+1,nums,one,res);
            one.pop_back();
        }
    }
};