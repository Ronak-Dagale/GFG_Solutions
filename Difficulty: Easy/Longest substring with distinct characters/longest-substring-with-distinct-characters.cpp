//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_map<char,int>mp;
        int ans=1;
        int left=0;
        mp[s[0]]=0;
        for(int i=1;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end() || mp[s[i]]<left)
            {
                mp[s[i]]=i;
                ans=max(ans,i-left+1);
            }
            else
            {
                left=mp[s[i]]+1;
                mp[s[i]]=i;
                ans=max(i-left+1,ans);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends