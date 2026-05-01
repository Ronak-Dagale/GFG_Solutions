class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        int n = arr.size();
        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++) {
            q.push(arr[i]);

            if(q.size() > k) {
                q.pop();
            }

            if(q.size() == k) {
                ans[i] = q.top();
            }
        }

        return ans;
    }
};