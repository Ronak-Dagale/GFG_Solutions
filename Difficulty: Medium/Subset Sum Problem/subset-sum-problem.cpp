//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool solve(vector<int>& arr,int id,int sum)
  {
      if(sum==0) return 1;
      if(sum<0) return 0;
      if(id>=arr.size()) return 0;
      // incl
      bool incl=solve(arr,id+1,sum-arr[id]);
      
      if(incl) return incl;
      // excl
      bool excl=solve(arr,id+1,sum);
      
      return excl;
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        // vector<vector<int>>dp(n,vector<int>(sum+1));
        bool ans=solve(arr,0,sum);
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends