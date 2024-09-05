//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
 

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        bool flag=1;
        string ans="";
        int i=0;
        while(flag)
        {
            char ch=arr[0][i];
            bool match=1;
          for(int j=0;j<arr.size();j++)
          {
             if(i+1>=arr[j].size())flag=0;
             if(ch!=arr[j][i])
             {
                 match=0;
                 break;
             }
          }
          i++;
          
           if(match)
             ans.push_back(ch);
             else 
             break;
          
        }
        if(ans=="") return "-1";
          return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends
