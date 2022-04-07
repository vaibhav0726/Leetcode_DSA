class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int bcount=0,count=0;
        for(auto it:nums){
            if(it < target)
                bcount++;
            else if(target == it)
                count++;
        }
        vector<int> v;
        for(int i=0; i<count; i++){
            v.push_back(bcount++);
        }
        return v;
    }
};