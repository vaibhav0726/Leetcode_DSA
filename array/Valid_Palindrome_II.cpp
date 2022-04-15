// Given a string s, return true if the s can be palindrome after deleting at most one character from it.
class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size()-1;
        for(int i=0; i<s.size()/2; i++){
            if(s[i]!=s[n]){
                return isPalindrome(s, i+1, n) || isPalindrome(s, i, n-1);
            }
            else{
                n--;
            }
        }
        return true; 
    }
    
    bool isPalindrome(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j])
                return false;
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
};
