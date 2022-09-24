class Solution {
public:
    char repeatedCharacter(string str) {
        char count_Arr[256];
        fill(count_Arr, count_Arr+256, -1);
        for(int i = 0; i<str.length(); i++){
            int idx = count_Arr[str[i]];
            if(idx == -1){
                count_Arr[str[i]]++;
            }
            else{
                return str[i];
            }
        }
        return 'o';
    }
    
};