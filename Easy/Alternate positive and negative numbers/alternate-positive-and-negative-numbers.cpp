//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector<int>pos,neg;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>=0)
	        pos.push_back(arr[i]);
	        else
	        neg.push_back(arr[i]);
	    }
	    int k=0,i=0,j=0;
	    
	    if(pos.size()==0 || neg.size()==0)
	    return;
	    
	    while(i<pos.size() && j<neg.size())
	    {
	        arr[k]=pos[i];
	        k++;
	        arr[k]=neg[j];
	        k++;
	        i++;
	        j++;
	    }
	    while(i<pos.size())
	   {
	       arr[k]=pos[i];
	       k++;
	       i++;
	   }
	    
	    while(j<neg.size())
	   {
	       arr[k]=neg[j];
	       k++;
	       j++;
	   }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends