//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
       int cnt=0;
       int prev;
        int i=0;
        int z=2<<r-1;
        while(cnt-1<n)
        {
            prev=cnt;
           cnt=cnt+z;
           i++;
           
        }
        n=n-prev;
       
        if(i!=0)
        i--;
        
        
        string prv="";
        prv.push_back(s[i]);
        string ne="";
       // cout<<n<<endl;
        //  cout<<i<<prv<<endl;
        for(int j=0;j<r;j++)
        {
            for(int k=0;k<prv.size();k++)
            {
                if(prv[k]=='0')
                {
                    ne.push_back('0');
                    ne.push_back('1');
                }
                else
                {
                    ne.push_back('1');
                    ne.push_back('0');
                
                }
            }
           // cout<<ne<<endl;
            prv=ne;
            ne="";
        }
        return prv[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends