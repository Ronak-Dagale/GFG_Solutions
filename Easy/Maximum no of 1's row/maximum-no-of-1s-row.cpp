//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int minisolve(vector <vector <int>> &Mat,int s,int e,int id)
    {
        int ans=0;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            
            if(Mat[id][mid]==1)
            {
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return ans;
    }
    int maxisolve(vector <vector <int>> &Mat,int s,int e,int id)
    {
         int ans=0;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            
            if(Mat[id][mid]==1)
            {
                ans=mid;
                s=mid+1;
            }
            else
            s=mid+1;
        }
        return ans;
    }
        int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
            // your code here
            int ans=-1;
            int cnt=INT_MIN;
            
            for(int i=0;i<N;i++)
            {
                int id=maxisolve(Mat,0,M-1,i)-minisolve(Mat,0,M-1,i);
                //cout<<id<<endl;
                if(id>cnt)
                {
                    ans=i;
                    cnt=id;
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}
// } Driver Code Ends