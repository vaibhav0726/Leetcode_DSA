// Given an integer array arr, and an integer target, return the number of tuples i, j, k 
// such that i < j < k and arr[i] + arr[j] + arr[k] == target.
// As the answer can be very large, return it modulo 109 + 7.


// solution:- 

// 3 cases covers all possible combination:
// 1. i == j == k
// 2. i == j != k
// 3. i < k && j < k


// time:- O(n*n)
// space:- O(n)

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long> m;
        for(auto it: arr){
            m[it]++;
        }
        long res = 0;
        for(auto it : m){
            for(auto it2: m){
                int i = it.first, j = it2.first, k = target -i -j;
                if(!m.count(k))
                    continue;
                if(i == j && j == k)
                    res += m[i] * (m[i] - 1) * (m[i] -2) / 6; // uses 6 bcz the number is repeating three times (so 3!)
                else if (i == j && j != k)
                    res += m[i] * (m[i] - 1) / 2 * m[k]; // uses /2 bcz the number is repeating two times(so 2!)
                else if(i < j && j < k)
                    res += m[i] * m[j] * m[k]; // here every number is unique so nothing will get in denominator
            }
        }
        return res % int(1e9 + 7); 
    }
};



