class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        for(int i=digits.size()-1; i>=0; i--){
            if(i==digits.size()-1) digits[i] += 1;
            if(carry) digits[i] += 1, carry = 0;
            if(digits[i] > 9){
                digits[i] %= 10;
                carry = 1;
            }
        }
        if(carry){
            vector<int> ans;
            ans.push_back(1);
            for(auto i: digits){
                ans.push_back(i);
            }
            return ans;
        }
        return digits;
    }
};