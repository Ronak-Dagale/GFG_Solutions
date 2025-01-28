//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void solve(string&s,int id,set<string>&st)
  {
      if(id>=s.size())
      {
          return;
      }
      st.insert(s);
      
      for(int j=id;j<s.size();j++)
      {
          swap(s[id],s[j]);
          solve(s,id+1,st);
          swap(s[id],s[j]);
      }
     
  }
    vector<string> findPermutation(string &s) {
        // Code here there
       int n=s.size();
       set<string>st;
       
       solve(s,0,st);
       vector<string>ans(st.begin(),st.end());
       return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends