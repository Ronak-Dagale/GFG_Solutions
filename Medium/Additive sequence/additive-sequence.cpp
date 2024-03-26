//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool isAdditiveSequence(string n) {
        // Your code here
        if(n.size()<3) return 0;
        
        string ans,s1;
        int sz=n.size();
        
        for(int i=0;i<min(sz-1,10);i++)
        {
            s1.push_back(n[i]);
            string s2="";
            for(int j=i+1;j<min(sz,10);j++)
            {
                s2.push_back(n[j]);
                ans=s1+s2;
                int a=stoi(s1);
                int b=stoi(s2);
                while(ans.size()<sz)
                {
                    int sum=a+b;
                    string s=to_string(sum);
                    if(sz-ans.size()<s.size())
                    break;
                    ans+=s;
                    a=b;
                    b=sum;
                    if(ans==n) return 1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends