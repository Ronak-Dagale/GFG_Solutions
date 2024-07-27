//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  int lcs(string& s1,string& s2,int i,int j,vector<vector<int>>&dp)
  {
      if(i>=s1.size() || j>=s2.size())
      return 0;
      
      int ans=0;
      if(dp[i][j]!=-1)
      return dp[i][j];
      
      if(s1[i]==s2[j])
      {
          ans=1+lcs(s1,s2,i+1,j+1,dp);
      }
      
      ans=max(ans,lcs(s1,s2,i+1,j,dp));
      ans=max(ans,lcs(s1,s2,i,j+1,dp));
      
      return dp[i][j]=ans;
  }
    int countMin(string str){
    //complete the function here
    string st=str;
    reverse(st.begin(),st.end());
    int n=str.size();
    
    vector<vector<int>>dp(n+1,vector<int>(n,-1));
    return str.size()-lcs(str,st,0,0,dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends