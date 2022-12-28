class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
//         brute force (TLE)
        // int i=0;
        // while(k--){
        //     sort(piles.begin(), piles.end(), greater<int>());
        //     piles[0] = piles[0] - (piles[0]/2);
        // }
        // int sum = 0;
        // for(int i=0; i<piles.size(); i++){
        //     sum += piles[i];
        // }
        // return sum;
        
        // Efficient solution using priority_queue
        priority_queue<int> heap(piles.begin(), piles.end());
        int totalSum = accumulate(piles.begin(), piles.end(), 0);
        
        while(k--){
            int curr = heap.top();
            heap.pop();
            int remove = curr / 2;
            totalSum -= remove;
            heap.push(curr - remove);
        }
        
        return totalSum;
    }
};