//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
        string ans;
        int i=0,j=0,curr=0;
        
        while(i<n && j<n)
        {
            string str=s.substr(i,j-i+1);
            if(s.find(str,j+1)!=string::npos)
            {
                int len=str.size();
                if(len>curr)
                {
                    curr=len;
                    ans=str;
                }
                j++;
            }
            else
            i++;
        }
        
        if(ans.empty())
        return "-1";
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends