class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0, prev = 0, cur = 0;
        for(auto i : nums) {
            cur = max(prev, i + prev2);
            prev2 = prev;
            prev = cur;
        }
        return cur;
    }
};