//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>l(n),r(n);
        int temp=0;
        for(int i=0;i<n;i++)
        {
            temp=max(temp,arr[i]);
            l[i]=temp;
        }
        temp=0;
        for(int i=n-1;i>=0;i--)
        {
            temp=max(temp,arr[i]);
            r[i]=temp;
        }
        
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int p=min(l[i],r[i]);
            ans+=(p-arr[i]);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends