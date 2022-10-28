class Solution {
private:
    bool areSame(int countS[], int countP[]){
        for(int i=0; i<256; i++){
            if(countS[i] != countP[i])
                return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.length()> s.length()) return ans;
        int sLen = s.length(), pLen = p.length();
        int countS[256] = {0}, countP[256] = {0};
        for(int i=0; i<pLen; i++){
            countS[s[i]]++;
            countP[p[i]]++;
        }
        int i;
        for(i=pLen; i<sLen; i++){
            if(areSame(countS, countP))
                ans.push_back(i-pLen);
            countS[s[i]]++;
            countS[s[i-pLen]]--;
        }
        if(areSame(countS, countP))
            ans.push_back(i-pLen);
        return ans;
    }
};