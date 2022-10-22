class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        bool isOdd = false;
        for(char &c:s)m[c]++;
        int result = 0;
        for(auto &c: m){
            if(c.second % 2 == 0) result += c.second;
            else{
                result += c.second - 1;
                isOdd = true;
            }
        }
        if(isOdd) result++;
        return result;

    }
};