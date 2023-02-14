class Solution {
public:
    string addBinary(string a, string b) {
//         string s = "";
        
//         int c = 0, i = a.size() - 1, j = b.size() - 1;
//         while(i >= 0 || j >= 0 || c == 1)
//         {
//             c += i >= 0 ? a[i --] - '0' : 0;
//             c += j >= 0 ? b[j --] - '0' : 0;
//             s = char(c % 2 + '0') + s;
//             c /= 2;
//         }
        
//         return s;
        int i = a.length()-1;
        int j = b.length()-1;
        string ans;
        int carry = 0;
        
        while(i>=0 || j>=0 || carry){
            if(i>=0){
                carry += a[i] - '0';
                i--;
            }
            if(j>=0){
                carry += b[j] - '0';
                j--;
            }
            
            ans += (carry%2 + '0');
            carry = carry/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};