class Solution {
public:
    int calculate(string s) {
        int ans = 0, currAns = 0;
        int sign = 1;
        int n = s.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            if(isdigit(s[i])){
                currAns = s[i] - '0';
                while(i+1 < n && isdigit(s[i+1])){
                    currAns = currAns * 10 + (s[i+1]-'0');
                    i++;
                }
                currAns *= sign;
                ans = ans + currAns;
                currAns = 0;
            }
            else if(s[i] == '+'){
                sign = 1;
            }else if(s[i] == '-'){
                sign = -1;
            }
            else if(s[i] == '('){
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                int prevSign = st.top();
                st.pop();
                ans = ans * prevSign;
                int prevAns = st.top();
                st.pop();
                ans = ans + prevAns;
            }
        }
        return ans;
    }
};