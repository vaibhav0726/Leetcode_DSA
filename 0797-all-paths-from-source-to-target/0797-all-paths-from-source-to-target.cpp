class Solution {
    void dfs(vector<vector<int>>& graph, vector<int> res, int src, int des, vector<vector<int>> &ans){
        res.push_back(src);
        if(src == des){
            ans.push_back(res);
            return;
        }
        for(auto i : graph[src]){
            // res.push_back(i);
            dfs(graph, res, i, des, ans);
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans; vector<int> res;
        // res.push_back(0);
        dfs(graph, res, 0, graph.size()-1, ans);
        return ans;
    }
};