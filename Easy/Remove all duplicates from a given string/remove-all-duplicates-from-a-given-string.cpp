//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    string ans="";
	    vector<int>up(26,0);
	    vector<int>low(26,0);
	    
	    for(int i=0;i<str.size();i++)
	    {
	        if(str[i]>='A' && str[i]<='Z')
	        {
	            up[str[i]-'A']++;
	            if(up[str[i]-'A']==1)
	            ans.push_back(str[i]);
	        }
	        else
	        {
	          low[str[i]-'a']++;
	            if(low[str[i]-'a']==1)
	            ans.push_back(str[i]);  
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends