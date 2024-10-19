//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    // your code here
	    int i=A.size()-1;
	    int j=B.size()-1;
	    
	    string ans="";
	    int carry=0;
	    int sum=0;
	    
	    while(i>=0 || j>=0)
	    {
	        if(i>=0 && j>=0)
	        {
	            int x=A[i]-'0';
	            int y=B[j]-'0';
	            sum=(x+y+carry)%2;
	            carry=(x+y+carry)/2;
	            
	            ans.push_back(sum+'0');
	            i--;
	            j--;
	        }
	        else if(i>=0)
	        {
	            int x=A[i]-'0';
	            sum=(x+carry)%2;
	            carry=(x+carry)/2;
	            
	            ans.push_back(sum+'0');
	            i--;
	        }
	        else if(j>=0)
	        {
	           int x=B[j]-'0';
	            sum=(x+carry)%2;
	            carry=(x+carry)/2;
	            
	            ans.push_back(sum+'0');
	            j--;  
	        }
	    }
	    if(carry!=0)
	    ans.push_back(carry+'0');
	    
	    string ans1="";
	    int k=ans.size()-1;
	    
	    while(ans[k]=='0')
	    k--;
	    
	    while(k>=0) ans1.push_back(ans[k--]);
	    
	    if(ans1.size()==0) ans1.push_back('0');
	    return ans1;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
