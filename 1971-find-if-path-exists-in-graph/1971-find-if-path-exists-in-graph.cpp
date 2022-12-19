class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<bool> used(n, false);
        used[start] = true;
        bool newUsedFound = true;
        while (!used[end] && newUsedFound) {
            newUsedFound = false;
            for (int i = edges.size() - 1; i >= 0; i--) {
                if (used[edges[i][0]]) {
                    if (!used[edges[i][1]])  newUsedFound = used[edges[i][1]] = true;
                } else if (used[edges[i][1]]) {
                    newUsedFound = used[edges[i][0]] = true;
                }
            }
        }
        return used[end];
    }
};