//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        // code here
        vector<int>fre(32,0);
        
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<32;j++)
            {
                fre[j]+=(arr[i]>>j)&1;
            }
        }
        
        int ans=0;
        
        for(int i=0;i<32;i++)
        {
            ans+=(fre[i]%3)<<i;
        }
        return ans;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends