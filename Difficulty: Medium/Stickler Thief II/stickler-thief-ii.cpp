//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
 int solve(vector<int>& arr, int id, int e, vector<int>& dp) {
    if (id > e) return 0;
    if (dp[id] != -1) return dp[id];

    // Take the element and move to `id+2`
    int take = arr[id] + solve(arr, id + 2, e, dp);
    
    // Skip the element and move to `id+1`
    int skip = solve(arr, id + 1, e, dp);

    return dp[id] = max(take, skip);
}

int maxValue(vector<int>& arr) {
    int n = arr.size();
    
    // Edge case: If there's only one element, return it
    if (n == 1) return arr[0];

    vector<int> dp1(n, -1), dp2(n, -1);

    int ans1 = solve(arr, 0, n - 2, dp1);  // Exclude last element
    int ans2 = solve(arr, 1, n - 1, dp2);  // Exclude first element

    return max(ans1, ans2);
}
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends