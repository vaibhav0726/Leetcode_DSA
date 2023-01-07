class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, curr = 0, si = 0;
        for(int i=0; i<cost.size(); i++){
            total = total + (gas[i]-cost[i]);
            curr = curr + (gas[i]-cost[i]);
            if(curr < 0){
                curr = 0;
                si = i+1;
            }
        }
        if(total < 0){
            return -1;
        }
        
        return si;
    }
};