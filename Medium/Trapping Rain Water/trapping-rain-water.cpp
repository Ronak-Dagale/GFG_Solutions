//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<int>l(n),r(n);
        int temp=0;
        for(int i=0;i<n;i++)
        {
            temp=max(temp,arr[i]);
            l[i]=temp;
        }
        temp=0;
        for(int i=n-1;i>=0;i--)
        {
            temp=max(temp,arr[i]);
            r[i]=temp;
        }
        
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int p=min(l[i],r[i]);
            ans+=(p-arr[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends