//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
  
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>ans(n,0);
        ans[0]=arr[0];
        if(n==1) return ans[n-1];
        
        ans[1]=max(arr[0],arr[1]);
        if(n==2) return ans[n-1];
        
        for(int i=2;i<n;i++)
        {
            ans[i]=max(ans[i-2]+arr[i],ans[i-1]);
        }
        return ans[n-1];
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
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends