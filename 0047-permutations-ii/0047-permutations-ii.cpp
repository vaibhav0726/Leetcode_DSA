class Solution {
private:
    void solve(vector<int>& nums, set<vector<int>> &ans, vector<bool> &isAdded, vector<int> v){
        if(v.size() >= nums.size()){
            ans.insert(v);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(isAdded[i] == false){
                isAdded[i] = true;
                v.push_back(nums[i]);
                solve(nums, ans, isAdded, v);
                isAdded[i] = false;
                v.pop_back();
            }
            
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> ans;
        vector<int> v;
        vector<bool> isAdded(nums.size());
        fill(isAdded.begin(), isAdded.end(), false);
        solve(nums, ans, isAdded, v);
        copy(ans.begin(), ans.end(), back_inserter(res));
        return res;
    }
};