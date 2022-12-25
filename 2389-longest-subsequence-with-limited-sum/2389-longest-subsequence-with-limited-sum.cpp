class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=0; i<queries.size(); i++){
            int j=0;
            int sum = 0;
            while(j<nums.size() && sum + nums[j] <= queries[i]){
                sum += nums[j++];
            }
            // if(sum == queries[i] || j==nums.size()){
            //     ans.push_back(j);
            // }
            // else{
            //     ans.push_back(j-1);
            // }
            ans.push_back(j);
        }
        return ans;
    }
};