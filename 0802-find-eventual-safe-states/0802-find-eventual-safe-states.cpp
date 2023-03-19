class Solution {
    bool dfs(vector<vector<int>>& graph, int src, vector<bool> &vis, vector<bool> &recursionStack, vector<bool> &check ){
        vis[src] = true;
        recursionStack[src] = true;
        for(int &i: graph[src]){
            if(!vis[i]){
                if(dfs(graph, i, vis, recursionStack, check)){
                    check[i] = false;
                    return true; // has cycle
                }
            }
            else if(recursionStack[i]){
                check[i] = false;
                return true; // has cycle
            }
        }
        recursionStack[src] = false;
        check[src] = true;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, list<int>> adj;
        int n = graph.size();
        // vector<int> outDegree(n, 0);
        // for(int i=0; i<n; i++){
        //     for(int &edge: graph[i]){
        //         if(edge == i) continue;
        //         // outDegree[i]++;
        //         adj[i].push_back(edge);
        //     }
        // }
        
        vector<bool> vis(n, false), recursionStack(n, false), check(n, false);
        for(int i=0; i<n; i++){
            if(!vis[i])
                dfs(graph, i, vis, recursionStack, check);        
        }
        
        vector<int> safeNodes;
        for(int i=0; i<n; i++){
            if(check[i]){
                safeNodes.push_back(i);
            }
        }
        
        return safeNodes;
    }
};