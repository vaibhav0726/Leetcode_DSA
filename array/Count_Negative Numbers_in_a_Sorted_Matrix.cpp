class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), c=0, count=0, r=m-1;
        while(r>=0 && c<n){
            if(grid[r][c]<0){
                r--;
                count += n-c;
            }
            else{
                c++;
            }
        }
        return count;
    }
};
