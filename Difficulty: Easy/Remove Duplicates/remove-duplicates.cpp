//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        vector<bool>cnt(26,0);
        for(int i=0;i<str.size();i++)
        {
            if(cnt[str[i]-'a'])
            {
              str.erase(str.begin()+i,str.begin()+i+1);  
              i--;
            //  cout<<str<<endl;
            }
            else
            {
                cnt[str[i]-'a']=1;
            }
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends