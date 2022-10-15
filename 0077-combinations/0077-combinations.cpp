class Solution {
private:
    void solve(vector<int> &ques, vector<vector<int>> &ans, vector<int> v, int k, int idx){
        if(k == 0){
            ans.push_back(v);
            return;
        }
        
        for(int i = idx; i<ques.size(); i++){
            v.push_back(ques[i]);
            solve(ques, ans, v, k-1, i+1);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ques;
        vector<int> v;
        for(int i=1; i<=n; i++){
            ques.push_back(i);
        }
        solve(ques, ans, v, k, 0);
        return ans;
    }
};