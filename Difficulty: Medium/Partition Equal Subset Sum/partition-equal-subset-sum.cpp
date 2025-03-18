//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool solve(vector<int>& arr,int x, vector<vector<int>>&dp,int id)
  {
      if(x==0) return 1;
      if(x<0) return 0;
      
      if(id>=arr.size()) return 0;
      if(dp[id][x]!=-1) return dp[id][x];
      bool r1=solve(arr,x-arr[id],dp,id+1);
      if(r1) {
          dp[id][x]=1;
          return r1;
      }
      
      bool r2=solve(arr,x,dp,id+1);
      dp[id][x]=r2;
      
      return r2;
  }
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum=0;
        for(int i=0;i<arr.size();i++)sum+=arr[i];
        
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        if(sum%2!=0) return 0;
        
        return solve(arr,sum/2,dp,0);
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
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends