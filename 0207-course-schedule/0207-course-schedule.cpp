class Solution {
    bool bfs(unordered_map<int, list<int>> &adj, int v, vector<int> &indegrees){
        
        queue<int> q;
        for(int i=0; i<v; i++)
            if(indegrees[i] == 0)
                q.push(i);
        
        int count = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(int &i: adj[front]){
                indegrees[i]--;
                if(indegrees[i] == 0){
                    q.push(i);
                }
            }
            count++;
        }
        
        return v==count;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        int n = prerequisites.size();
        for(int i=0; i<n; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }        
        vector<int> indegrees(numCourses, 0);
        for(int i=0; i<prerequisites.size(); i++){
            indegrees[prerequisites[i][1]]++;
        }
                
        return bfs(adj, numCourses, indegrees);
    }
};