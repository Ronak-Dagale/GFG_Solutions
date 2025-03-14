//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &S) {
        // code here
          int start=0,end=0,len=0,n=S.length();
        for(int i=0;i<n;i++)
        {
            int s=i-1,e=i+1;
            while(s>=0 && e<n && S[s]==S[e])
            {
                if(e-s+1>len)
                {
                    len=e-s+1;
                    start=s;
                    end=e;
                }
                s--;
                e++;
            }
            s=i-1;
            e=i;
            while(s>=0 && e<n && S[s]==S[e])
            {
                if(e-s+1>len)
                {
                    len=e-s+1;
                    start=s;
                    end=e;
                }
                s--;
                e++;
            }
        }
        string ans="";
        for(int i=start;i<=end;i++)
        {
            ans+=S[i];
        }
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
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends