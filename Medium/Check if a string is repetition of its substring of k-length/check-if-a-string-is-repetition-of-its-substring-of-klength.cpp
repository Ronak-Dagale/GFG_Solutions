//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    // Your Code Here
	      if(n%k!=0){
            return 0;
        }
        vector<string>v;
        string st="";
        for(int i=0;i<n;i++){
            st+=s[i];
            if(st.length()==k){
                v.push_back(st);
                st="";
            }
        }
        set<string>a;
        for(int i=0;i<v.size();i++){
             a.insert(v[i]);
        }
        if(a.size()>2){
            return 0;
        }
        else 
        return 1;
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends