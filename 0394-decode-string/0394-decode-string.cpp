class Solution {
public:
    string decodeString(string s) {
        stack<char> str;
        for(int i=0; i<s.length(); i++){
            if(s[i] != ']'){
                str.push(s[i]);
            }
            else{
                string curr_str = "";
                while(str.top() != '['){
                    curr_str = str.top() + curr_str;
                    str.pop();
                }
                str.pop(); // for removing '['
                string number = "";
                while(!str.empty() && isdigit(str.top())){
                    number = str.top() + number;
                    str.pop();
                }
                int number_of_times = stoi(number);
                while(number_of_times--){
                    for(int j=0; j<curr_str.size(); j++){
                        str.push(curr_str[j]);
                    }
                }
            }
        }
        string ans = "";
        while(!str.empty()){
            ans = str.top() + ans;
            str.pop();
        }
        return ans;
    }
};