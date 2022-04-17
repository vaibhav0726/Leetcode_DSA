

class Solution {
public:
    string digitSum(string s, int k) {
        
        while(s.size() > k){
            string str = s;
            s = "";
            int i = 0;
            while(i < str.size()){
                int sum = 0;
                int k1 = k;
                while(i < str.size() && k1-- >0 ){
                    sum += (int)str[i] - 48;
                    i++; 
                }
                string temp = to_string(sum);
                s = s + temp;
            }
            // cout << s << endl;
        }
        return s;
    }
};
