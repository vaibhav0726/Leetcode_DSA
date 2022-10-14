class Solution {
private:
    void solve(vector<int>& candidates, int target, int idx, vector<int> v, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        
        for(int i = idx; i<candidates.size(); i++){
            if(target >= candidates[i]){
                v.push_back(candidates[i]);
                solve(candidates, target-candidates[i], i, v, ans);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(candidates, target, 0, v, ans);
        return ans;
    }
};