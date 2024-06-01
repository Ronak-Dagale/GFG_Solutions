//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        vector<int>fre(27,0);
        int ans=0;
        
        for(int i=0;i<s.size();i++)
         fre[s[i]-'a'+1]++;
        
        for(int i=1;i<27;i++)
        {
            if(fre[i]!=0 && i&1 && fre[i]&1)ans++;
            else if(fre[i]!=0 && i%2==0 && fre[i]%2==0) ans++;
        }
        return ans&1?"ODD":"EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends