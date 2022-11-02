class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char freq[256] = {};
        for(int i=0; i<s.length(); i++){
            if(!freq[s[i]]){
                for(auto c: freq){
                    if(c == t[i]) return false;
                }
                freq[s[i]] = t[i];
            }
            else if(freq[s[i]] != t[i])
                return false;
        }
        return true;
    }
};