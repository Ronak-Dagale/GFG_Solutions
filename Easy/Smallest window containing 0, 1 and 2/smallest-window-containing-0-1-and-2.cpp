//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int ans=INT_MAX;
        int i=0,j=0,zc=0,oc=0,tc=0;
        
        while(i<S.size())
        {
            if(zc>=1 && oc>=1 && tc>=1)
            {
                ans=min(ans,(i-j));
                if(S[j]=='0')
                {
                    zc--;
                    j++;
                }
                else if(S[j]=='1')
                {
                    oc--;
                    j++;
                }
                else
                {
                    tc--;
                    j++;
                }
                
            }
            else
            {
                
                if(S[i]=='0')
            {
                zc++;
            }
            else if(S[i]=='1')
            {
                oc++;
            }
            else if(S[i]=='2')
            {
                tc++;
            }
            i++;
            }
            
        }
        while(zc>=1 && oc>=1 && tc>=1)
        {
            ans=min(ans,(i-j));
            if(S[j]=='0')
                {
                    zc--;
                    j++;
                }
                else if(S[j]=='1')
                {
                    oc--;
                    j++;
                }
                else
                {
                    tc--;
                    j++;
                }
        }
        
        if(ans==INT_MAX)
        return -1;
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
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends