class Solution {
    bool isitPossible(vector<int>& weights, int c, int days){
        int sum = 0, daysNeeded = 1;
        for(auto weight : weights){
            sum += weight;
            if(sum > c){
                sum = weight;
                daysNeeded++;
            }
        }
        return daysNeeded <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = 0, totalLoad = 0;
        for(auto weight : weights){
            totalLoad += weight;
            maxWeight = max(maxWeight, weight);
        }
        int l = maxWeight, r = totalLoad;
        while(l < r){
            int mid = l + (r - l)/2;
            if(isitPossible(weights, mid, days)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};