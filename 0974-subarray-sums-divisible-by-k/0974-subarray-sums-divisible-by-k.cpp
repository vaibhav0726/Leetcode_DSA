class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int K) {
        vector<int> count(K, 0);
        int sum = 0;
        for (int n : nums) {
            sum += (n%K + K) % K;
            count[sum % K]++;
        }
        int res = count[0];
        for(int c : count){
            res += (c*(c-1))/2;
        }
        return res;
    }
};