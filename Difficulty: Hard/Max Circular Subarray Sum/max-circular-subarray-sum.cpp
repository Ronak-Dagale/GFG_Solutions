//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int max_so_far = 0 ; // Track the maximum Subarray Sum
        int min_so_far = 0; // Track the minimum Subarray Sum
        int minSum = arr[0] ; // Puri Array useme Jo Minimum sum Sub array
        int maxSum = arr[0]; // Puri Array useme Jo Maximum sum Sub array;
        int total = 0;
        for(int i=0;i<arr.size();i++){
            
            // Kadane's Algorithm for Maximum Subarray Sum
            max_so_far = max(max_so_far + arr[i],arr[i]);
            maxSum = max(maxSum,max_so_far);
            
            // Kadane's Algorithm for Minium Subarray Sum
            min_so_far = min(min_so_far + arr[i],arr[i]);
            minSum = min(minSum,min_so_far);
            
            total += arr[i];
        }
        return max(total - minSum,maxSum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends