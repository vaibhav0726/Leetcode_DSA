class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m;
        unordered_set<int> s;
        for(int i=0; i<arr.size();++i){
            // if(m.find(arr[i])!=m.end())
            //     m[arr[i]]++;
            m[arr[i]]++;
        }
        for(auto it=m.begin();it!=m.end();it++){
            int x = it->second;
            if(s.find(x)!=s.end())
                return false;
            s.insert(x);
        }
        return true;
        
    }
};