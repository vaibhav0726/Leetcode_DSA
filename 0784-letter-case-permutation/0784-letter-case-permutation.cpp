class Solution {
private:
    void solve(vector<string> &ans, string s, vector<bool> &isAdded, int idx){
        if(idx >= s.size()){
            return;
        }
        for(int i = idx; i<s.length(); i++){
            if(isalpha(s[i]) && isAdded[i] == false){
                isAdded[i] = true;
                if(islower(s[i]))
                    s[i] = s[i] - 32;
                else
                    s[i] = s[i] + 32;
                ans.push_back(s);
                solve(ans, s, isAdded, i);
                if(islower(s[i]))
                    s[i] = s[i] - 32;
                else
                    s[i] = s[i] + 32;
                isAdded[i] = false;
            }
        }
    }

public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        ans.push_back(s);
        vector<bool> isAdded(s.length(), false);
        solve(ans, s, isAdded, 0);
        return ans;
    }
};