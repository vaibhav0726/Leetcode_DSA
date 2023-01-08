class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
//         brute force
//         int n = points.size();
//         if(n<=2) return n;
//         int maxi = 2;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 int x1 = points[i][0];
//                 int x2 = points[j][0];
//                 int y1 = points[i][1];
//                 int y2 = points[j][1];
                
//                 int total = 2;
//                 for(int k=0; k<n; k++){
//                     if(k!=i && j!=k){
//                         int x = points[k][0];
//                         int y = points[k][1];

//                         if((y2 - y1)*(x - x1) == (x2 - x1)*(y - y1))
//                             total++;
//                     }
//                 }
//                 maxi = max(total, maxi);
//             }
//         }
//         return maxi;
        
        
        
//         efficient solution
        int n = points.size();
        if (n == 1) {
            return 1;
        }
        int result = 2;
        for (int i = 0; i < n; i++) {
            unordered_map<double, int> cnt;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    cnt[atan2(points[j][1] - points[i][1], points[j][0] - points[i][0])]++;
                }
            }
            for (auto [h, count] : cnt) {
                result = max(result, count + 1);
            }
        }
        return result;
    }
};