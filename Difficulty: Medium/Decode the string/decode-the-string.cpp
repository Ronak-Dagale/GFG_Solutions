//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<string>st;
        
        for(int i=0;i<s.size();i++){
            if(s[i]!=']'){
                string tmp="";
                tmp.push_back(s[i]);
                st.push(tmp);
            }
            else
            {
                string tmp="";
                while(st.top()!="["){
                    tmp+=st.top();
                    st.pop();
                }
                
                string num="";
                st.pop();
                while(!st.empty() && st.top()[0]>='0' && st.top()[0]<='9'){
                    num+=st.top();
                    st.pop();
                }
                reverse(num.begin(),num.end());
                int n=stoi(num);
                
                string res="";
                for(int i=0;i<n;i++){
                    res+=tmp;
                }
                
                st.push(res);
            }
        }
        
        string ans="";
        // reverse(ans.begin(),ans.end());
        while(!st.empty())
        {
            string tmp=st.top();
            ans+=tmp;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends