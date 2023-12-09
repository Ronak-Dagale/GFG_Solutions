//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  bool isstop(int n)
  {
      if(n==0) return 1;
      if(n==1) return 1;
      
      for(int i=2;i*i<=n;i++)
      {
          if(n%i==0)return 0;
      }
      return 1;
  }
  int solve2(int n)
  {
      map<int,int>mp;
      while(!isstop(n))
      {
          for(int i=2;i*i<=n;i++)
          {
              if(n%i==0)
              {
                  n=n/i;
                  mp[i]++;
                  break;
              }
          }
      }
      
      mp[n]++;
      int ans=0;
      for(auto v:mp)
      {
          int n=v.first;
          while(n!=0)
          {
              ans+=(n%10)*v.second;
              n=n/10;
          }
      }
      return ans;
  }
  int solve1(int n)
  {
      int ans=0;
      while(n!=0)
      {
         ans+=(n%10);
         n=n/10;
      }
      return ans;
  }
    int smithNum(int n) {
        // code here
        if(isstop(n)) return 0;
        int sum1=solve1(n);
        int sum2=solve2(n);
        //cout<<sum1<<" "<<sum2<<endl;
        if(sum1==sum2)
        return 1;
        
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends