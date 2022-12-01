class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int> q;
        int j = 1;
        vector<int> ans(arr.size()-k+1);
        for (int i = 0; i < k; i++) {
            while (!q.empty() && arr[i] > arr[q.back()]) {
                q.pop_back();
            }
            q.push_back(i); // add last
        }
        ans[0] = arr[q.front()];
        for (int i = k; i < arr.size(); i++) {
            while (!q.empty() && arr[i] > arr[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            if (!q.empty() && q.front() == i - k) {
                q.pop_front();
            }
            ans[j] = arr[q.front()];
            j++;
        }
        return ans;
    }
};