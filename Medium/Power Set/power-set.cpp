//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void solve(string s,int i, vector<string>&ans,string temp)
	{
	    if(i==s.size())
	    {
	        if(temp.size()>0)
	        {
	            ans.push_back(temp);
	        }
	        return;
	    }
	    solve(s,i+1,ans,temp);
	    temp.push_back(s[i]);
	    solve(s,i+1,ans,temp);
	   
	    
	}
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>ans;
		    string temp="";
		    solve(s,0,ans,temp);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends