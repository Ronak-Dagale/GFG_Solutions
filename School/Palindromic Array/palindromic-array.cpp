//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/
#include<vector>
class Solution {
public:
bool ispalin(int n)
{
    vector<int>chk;
    while(n)
    {
        chk.push_back(n%10);
        n=n/10;
    }
    int i=0,j=chk.size()-1;
    while(i<j)
    {
        if(chk[i]!=chk[j])
        return 0;
        
        i++;
        j--;
    }
    return 1;
}
    int PalinArray(int a[], int n)
    {
    	// code here
    	for(int i=0;i<n;i++)
    	{
    	    if(!ispalin(a[i]))
    	    return 0;
    	}
    	return 1;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends