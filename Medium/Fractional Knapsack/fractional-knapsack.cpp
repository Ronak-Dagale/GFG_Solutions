//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(Item a,Item b)
    {
        double x,y;
        x=double(a.value)/(double)(a.weight);
        y=double(b.value)/(double)(b.weight);
        
        return x>y;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double ans=0;
        sort(arr,arr+n,cmp);
        
        for(int i=0;i<n;i++)
        {
            if(W>0)
            {
               if(W-arr[i].weight>=0)
               {
                     ans=ans+(double)arr[i].value;
                     W=W-arr[i].weight;
               }
             
               else
               {
                   double temp=(double)(arr[i].value)/(double)(arr[i].weight);
                   ans=ans+temp*W;
                   W=0;
               }
               //cout<<ans<<endl;
            }
            else
            break;
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends