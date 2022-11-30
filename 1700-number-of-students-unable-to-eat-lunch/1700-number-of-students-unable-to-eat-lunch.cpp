class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0, 0};
        int n = students.size();
        for(int i= 0; i<students.size(); i++){
            count[students[i]]++;
        }
        for (int i = 0; i < n; i++) {
            count[sandwiches[i]]--;
            if (count[sandwiches[i]] < 0) 
                return n - i;
        }
        return 0;
    }
};