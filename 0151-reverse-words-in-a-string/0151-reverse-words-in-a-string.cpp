class Solution {
public:
    string reverseWords(string s) {
        int i = s.size()-1;
        string ans = "";
        while(i >= 0){
            string str = "";
            if(s[i] !=' '){
                while(i>=0 && s[i] !=' '){
                    str = s[i] + str;
                    i--;
                }
                ans = ans + " " + str;
            }
            while(i>=0 && s[i] == ' '){
                i--;
            }
        }
        return ans.substr(1,ans.size());
    }
};