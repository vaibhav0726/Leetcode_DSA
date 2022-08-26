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