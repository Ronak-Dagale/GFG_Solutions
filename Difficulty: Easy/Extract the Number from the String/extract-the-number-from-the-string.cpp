//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  long long solve(string s)
  {
      long long ans=0;
      int i=0;
      long long mul=1;
      while(i<s.size())
      {
        
          ans=(10*ans)+(s[i]-'0');
          i++;
      }
   
      return ans;
  }
    long long ExtractNumber(string sentence) {

        // code here
        long long ans=INT_MIN;
        int i=0;
        while(i<sentence.size())
        {
           string num="";
           while(i<sentence.size() && sentence[i]>='0' && sentence[i]<='9')
           {
               
               if(sentence[i]=='9')
               {
                   num="-1";
               }
               
               if(num!="-1")
               {
                   num.push_back(sentence[i]);
               }
               i++;
               
           }
           //cout<<num<<endl;
           if(num!="" && num!="-1")
           {long long temp=solve(num);
           ans=max(ans,temp);
               continue;
           }
           i++;
        }
        return ans==INT_MIN?-1:ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends