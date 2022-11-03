class Solution {
public:
    int countSubstrings(string s) {
        // axis orbit algo
        int count = 0;
        for(int i=0; i<s.length(); i++){
            int left = i, right = i;
            while(left >=0 && right < s.length() && s[left] == s[right]){
                count++;
                left--;
                right++;
            }
            left = i, right = i+1;
            while(left >=0 && right < s.length() && s[left] == s[right]){
                count++;
                left--;
                right++;
            }
        }
        return count;
    }
};