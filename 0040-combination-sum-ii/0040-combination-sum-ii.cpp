class Solution {
private:
    void solve(vector<int>& candidates, int target, int idx, vector<int> v, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        
        for(int i = idx; i<candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i-1])
                continue;
            if(target >= candidates[i]){
                v.push_back(candidates[i]);
                solve(candidates, target-candidates[i], i+1, v, ans);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, v, ans);
        return ans;
    }
};