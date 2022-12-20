class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        vis[0] = true;
        queue<int> q;
        for(int i=0; i<rooms[0].size(); i++){
            q.push(rooms[0][i]);
        }
        while(!q.empty()){
            int room = q.front();
            q.pop();
            if(!vis[room]){
                for(int i=0; i<rooms[room].size(); i++){
                    q.push(rooms[room][i]);
                }
                vis[room] = true;
            }
        }
        for(int i=0; i<n; i++){
            if(vis[i] == false){
                return false;
            }
        }
        
        return true;
        
    }
};