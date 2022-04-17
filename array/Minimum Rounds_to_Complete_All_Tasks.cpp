// You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. 
// In each round, you can complete either 2 or 3 tasks of the same difficulty level.

//  Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        for(int i=0; i< tasks.size(); i++){
            if(m.find(tasks[i]) != m.end()){
                m[tasks[i]] += 1;
            }
            else{
                m[tasks[i]] = 1;
            }
        }
              
        for(auto it: m){
            if(it.second < 2)
                return -1;
        }
        
        int count = 0;
        for(auto it: m){
            if(it.second == 2){
                count += 1;
            }
            else if(it.second == 3)
                count += 1;
            else
            {
                while(it.second > 3){
                    it.second = it.second - 3;
                    count += 1;
                }
                if(it.second != 0){
                    count += 1;
                }
            }
        }
        
        return count;
    }
};
