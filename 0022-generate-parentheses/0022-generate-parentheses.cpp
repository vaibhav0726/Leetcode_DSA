class Solution {
private:
    void solve(int close, int open, string ans, vector<string> &v, int n){
        if(ans.length() == 2*n) {
            v.push_back(ans);
            return;
        }
        if(open < n){
            solve(close, open+1, ans+'(', v, n);
        }
        if(close < open){
            solve(close+1, open, ans+')', v, n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string ans = "";
        vector<string> v;
        solve(0, 0, ans, v, n);
        return v;
    }
};