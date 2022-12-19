class StockSpanner {
public:
    StockSpanner() {
    }
    
//     storing price and result of it
    stack<pair<int, int>> st;
    
    int next(int price) {
        int ans = 1;
        while(!st.empty() && price>=st.top().first){
//             adding the result
            ans += st.top().second;
            st.pop();
        }
        st.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */