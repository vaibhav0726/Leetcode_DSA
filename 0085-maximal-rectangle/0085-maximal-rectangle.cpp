class Solution {
    int largestRectangleArea(vector < int > & heights) {
        int n = heights.size();
        stack < int > st;
        int leftsmall[n], rightsmall[n];
        for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (st.empty())
            leftsmall[i] = 0;
        else
            leftsmall[i] = st.top() + 1;
        st.push(i);
        }
        // clear the stack to be re-used
        while (!st.empty())
        st.pop();

        for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        if (st.empty())
            rightsmall[i] = n - 1;
        else
            rightsmall[i] = st.top() - 1;

        st.push(i);
        }
        int maxA = 0;
        for (int i = 0; i < n; i++) {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
        }
        return maxA;
    }
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int maxArea = 0;
        vector<int> heights(mat[0].size(), 0);
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            int area = largestRectangleArea(heights);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};