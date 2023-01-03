class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        // unordered_map<char, int> mp;
        // for(int i=0; i<jewels.size(); i++){
        //     mp[jewels[i]]++;
        // }
        // int count = 0;
        // for(int i=0; i<stones.size(); i++){
        //     if(mp[stones[i]] != 0) count++;
        // }
        // return count;
        
        // int res = 0;
        // unordered_set<char> setJ(J.begin(), J.end());
        // for (char s : S)
        //     if (setJ.count(s)) res++;
        // return res;
        
        map<int,int> mp;
        for(auto x: stones){
            mp[x]++;
        }
        int count=0;
        for(int i=0; i<jewels.size(); i++){
            int val =jewels[i];
            auto key = mp.find(val);
            if(key!=mp.end()){
                count += key->second;
                key->second = 0;
            }
        }
        return count;
    }
};