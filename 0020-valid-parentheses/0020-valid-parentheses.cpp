class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mp;
        mp['{'] = '}';        
        mp['['] = ']';
        mp['('] = ')';
        if(s.size()%2!=0)
            return false;

        for(int i=0; i<s.size(); i++){
            if((s[i] == '}' || s[i] == ')' || s[i] == ']') && st.empty()){
                return false;
            }
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(s[i] == mp[st.top()]){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};