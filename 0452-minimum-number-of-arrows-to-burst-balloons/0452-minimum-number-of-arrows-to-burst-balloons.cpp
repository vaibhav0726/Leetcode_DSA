class Solution {
private:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        for(int i=0; i<points.size(); i++){
            cout<<points[i][0]<<" "<<points[i][1]<<endl;
        }
        int arrows = 1;
        int end = points[0][1];
        for(int i=1; i<points.size(); i++){
            if(end >= points[i][0]){
                continue;
            }
            else{
                arrows++;
                end = points[i][1];
            }
        }
        return arrows;
    }
};