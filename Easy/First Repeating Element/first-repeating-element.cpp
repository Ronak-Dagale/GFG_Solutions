//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
        int ans=INT_MAX;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp[arr[i]]==0)
             mp[arr[i]]=i+1;
            else if(mp[arr[i]]!=0 && ans>mp[arr[i]])
            {
                ans=mp[arr[i]];
            }
            
        }
        return ans==INT_MAX?-1:ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}

// } Driver Code Ends