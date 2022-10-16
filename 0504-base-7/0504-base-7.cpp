class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return to_string(num);
        string s = "";
        bool isNegative = num < 0? true: false;
        if(isNegative) num = -1*num;
        while(num > 0){
            s = to_string(num%7) + s;
            num = num / 7;          
        }
        if(isNegative) return '-'+s;
        else return s;
    }
};