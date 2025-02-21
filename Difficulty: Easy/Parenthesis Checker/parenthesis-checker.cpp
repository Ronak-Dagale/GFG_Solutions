//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& x) {
        // code here
        unordered_map<char,bool>mp;
        mp['[']=1;
        mp['{']=1;
        mp['(']=1;
        stack<char>s;
        
        for(int i=0;i<x.size();i++)
        {
    
          if(mp[x[i]]) s.push(x[i]);
          else if((x[i]==']' && !s.empty() && s.top()=='[') || (x[i]=='}' && !s.empty() && s.top()=='{') || 
          (x[i]==')' && !s.empty()  && s.top()=='('))
          s.pop();
          else
          return 0;
        }
        return s.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends