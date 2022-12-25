class Solution {
private:
    bool isVowel(char ch)
    {
        // Make the list of vowels
        string str = "aeiouAEIOU";
        return str.find(ch) != string::npos;
    }
public:
    bool halvesAreAlike(string s) {
        int count_1 = 0, count_2 = 0;
        for(int i=0; i<s.length()/2; i++){
            if(isVowel(s[i])) count_1++;
        }
        
        for(int i=s.length()/2; i<s.length(); i++){
            if(isVowel(s[i])) count_2++;
        }
        return count_1 == count_2;
    }
};