class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        int count[26] = {0};
        for(auto c: s1) count[c-'a']++;
        int i=0, j=0, total_chars = s1.size();
        while(j < s2.length()){
            if(count[s2[j++] - 'a']-- > 0){
                total_chars--;
            }
            if(total_chars == 0) return true;
            if(j-i == s1.length() && count[s2[i++] - 'a']++ >= 0){
                total_chars++;
            }
        }
        return false;
    }
};

// https://leetcode.com/problems/permutation-in-string/discuss/638531/Java-or-C%2B%2B-or-Python3-or-Detailed-explanation-or-O(N)-time