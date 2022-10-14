class Solution {
private:
    void solve(vector<int>& candidates, int target, int idx, vector<int> v, vector<vector<int>> &ans){
		//means we achieved the target and adding it to ans (base case)
        if(target == 0){
            ans.push_back(v);
            return;
        }
        
        for(int i = idx; i<candidates.size(); i++){
			// runs when candidates element have smaller or equal value. Bigger value makes no sense here 
            if(target >= candidates[i]){
                v.push_back(candidates[i]);
                solve(candidates, target-candidates[i], i, v, ans); // i+1 because we have to take combinations and combinations we can't take same value another time.
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; // declared to store the answer 
        vector<int> v; 
		// passing it by reference
        solve(candidates, target, 0, v, ans);
		// finally returning the answer
        return ans;
    }
};
