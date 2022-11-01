class Solution {
public:
    string reverseWords(string s) {
        string str = "";
        string ans;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i] != ' '){
                str = str + s[i];
            }
            else{
                ans = " " + str + ans;
                str = "";
            }
        }
        ans = str + ans;
        return ans;
    }
};