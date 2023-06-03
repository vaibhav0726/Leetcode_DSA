class Solution {
public:    
    unordered_map<int, vector<int>> mp;
    int ans = 0, mx = 0;
    
    void dfs(int manager, vector<int>& iT){
        mx = max(ans, mx);
        for(auto employee: mp[manager]){
            ans += iT[manager];
            dfs(employee, iT);
//             backtracking
            ans -= iT[manager];
        }
    }

    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
//         making the graph
        for(int i=0; i<n; i++){
            int val = manager[i];
            if(val != -1)
                mp[val].push_back(i);
        }
        
        dfs(headID, informTime);
        
        return mx;
        
    }
};