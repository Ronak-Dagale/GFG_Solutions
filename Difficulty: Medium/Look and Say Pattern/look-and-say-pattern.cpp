//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        // code here
        string ans="1";
        
        while(--n)
        {
           string tmp="";
           for(int i=0;i<ans.size();i++)
           {
               char ch=ans[i];
               int cnt=0;
               while(i<ans.size() && ans[i]==ch)
               {
                   cnt++;
                   i++;
               }
               i--;
               
               tmp+=to_string(cnt);
               tmp.push_back(ch);
           }
           ans=tmp;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends