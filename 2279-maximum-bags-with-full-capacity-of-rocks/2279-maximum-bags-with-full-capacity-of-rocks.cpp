class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> difference;
        for(int i=0; i<capacity.size(); i++){
            difference.push_back(capacity[i] - rocks[i]);
        }
        sort(difference.begin(), difference.end());
        int i = 0;
        int count = 0;
        while(i<difference.size() && additionalRocks > 0){
            if(additionalRocks < difference[i]) break;
            additionalRocks -= difference[i];
            count++;
            i++;
        }
        
        return count;
        
    }
};