//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        string ans="";
        int i=str.size();
        string temp="";
        while(i>=0)
        {
            if(str[i]!='.')
            {
                temp.push_back(str[i]);
            }
            else
            {
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans.push_back('.');
                temp="";
            }
            i--;
        }
        reverse(temp.begin(),temp.end());
        ans+=temp;
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
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends