class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(i<j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else if(isalnum(s[i]) == 0){
                i++;
            }
            else if(isalnum(s[j]) == 0){
                j--;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
};

// Efficient
#include<bits/stdc++.h>
class Solution {
public:
    bool isPalindrome(string str){
        for(int i=0, j=str.size()-1; i<j ; i++,j--){
            while(isalnum(str[i]) == false && i<j) i++;
            while(isalnum(str[j]) == false && i<j) j--;
            if(tolower(str[i]) != tolower(str[j])) return 0;
        }
        return 1;
        
    }
};
