class Solution {
public:
    int firstUniqChar(string s) {
        int count_Arr[256] = {0};      
        
        for(int i=0; i<s.length(); i++){
            count_Arr[s[i]]++;
        }
        for(int i = 0; i<s.length(); i++){
            if(count_Arr[s[i]] == 1)
                return i;
        }
        return -1;
    }
};