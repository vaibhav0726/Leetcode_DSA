class Solution {
public:
//     similar to next greater element and daily temperature
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = INT_MIN;
        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int r = i;
                int h = heights[st.top()];
                st.pop();
                if(st.empty()){
                    ans = max(h*r, ans);
                }
                else{
                    int l = st.top();
                    ans = max((h*(r-l-1)), ans);                    
                }
            }
            st.push(i);
        }
        int r = heights.size();
        while(!st.empty()){
            int h = heights[st.top()];
            st.pop();
            if(st.empty()){
                ans = max(h*r, ans);
            }
            else{
                int l = st.top();
                ans = max((h*(r-l-1)), ans);                    
            }
        }
        return ans;
    }
};