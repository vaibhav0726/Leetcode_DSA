class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0, j=0; 
        vector<vector<int>> ans;
        while(i < firstList.size() && j < secondList.size()){
            if(firstList[i][0] <= secondList[j][1] && secondList[j][0] <= firstList[i][1]){
                int temp1 = max(firstList[i][0], secondList[j][0]);
                int temp2 = min(firstList[i][1], secondList[j][1]);
                ans.push_back({temp1, temp2});
            }
            if(firstList[i][1] < secondList[j][1]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};