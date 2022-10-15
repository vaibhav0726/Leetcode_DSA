class Solution {
private:
    void solve(vector<vector<int>> &ans, vector<int> &ques, vector<int> v, int k, int n, int idx){
        if(k==0 && n==0){
            ans.push_back(v);
            return;
        }
        if(n==0 || k==0) return;
        for(int i=idx; i<ques.size(); i++){
            if(ques[i] <= n){
                v.push_back(ques[i]);
                solve(ans, ques, v, k-1, n-ques[i], i+1);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        vector<int> ques;
        for(int i=1; i<=9; i++){
            ques.push_back(i);
        }
        solve(ans, ques, v, k, n, 0);
        return ans;
    }
};