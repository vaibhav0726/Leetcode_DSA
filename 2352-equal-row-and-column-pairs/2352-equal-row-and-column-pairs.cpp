class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int i, j, ans = 0, count;
        for (int k = 0; k < n; k++)
        {
            for (j = 0; j < n; j++)
            {
                count = 0;
                for (i = 0; i < n; i++)
                {
                    if (grid[k][i] == grid[i][j])
                        count++;
                }
                if (count == n)
                    ans++;
            }
        }
        return ans;

    }
};