class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        // code here
       int n = arr.size();
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + arr[i];

    long long ans = LLONG_MIN;
    multiset<long long> window; 

    for (int i = a; i <= n; i++) {
        // add prefix[i-a] (subarray starting point)
        window.insert(prefix[i - a]);

        // remove prefix[i-b-1] if it's out of range
        if (i - b - 1 >= 0) {
            window.erase(window.find(prefix[i - b - 1]));
        }

        // best subarray ending at i is prefix[i] - min(prefix in window)
        ans = max(ans, prefix[i] - *window.begin());
    }

    return (int)ans;
    }
};