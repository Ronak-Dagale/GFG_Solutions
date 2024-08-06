//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // code here
        int i=0;
        int cnt=0;
        while(i<str.size())
        {
            string temp="";
            cnt++;
            while(i<str.size() && str[i]!='.')
            {
              temp.push_back(str[i]);
              i++;
              
              if(temp.size()>3) return 0;
            }
            // cout<<temp<<endl;
            if(str[i]=='.') i++;
            
            if(temp.size()>0 && temp.size()<=3)
            {
              int v=stoi(temp);
              if(temp[0]=='0' && temp.size()>1)
              return 0;
              else if(v>255) 
              return 0;
            }
            else
            return 0;
            
            if(cnt>4)
            return 0;
        }
        if(cnt==4)
        return 1;
        else
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends