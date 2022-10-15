class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>> &ans, vector<bool> isAdded, vector<int> v){
        if(v.size() >= nums.size()){
            ans.push_back(v);
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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        vector<bool> isAdded(nums.size());
        fill(isAdded.begin(), isAdded.end(), false);
        solve(nums, ans, isAdded, v);
        return ans;
    }
};