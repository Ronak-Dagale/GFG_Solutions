class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        sort(x.begin(),x.end(),greater<int>());
        sort(y.begin(),y.end(),greater<int>());
        int ans=0;
        int i=0,j=0,hs=1,vs=1;
        while(i<x.size() || j<y.size()){
            if(i<x.size() && j<y.size()){
                if(x[i]>y[j])
                {
                   ans+=(x[i]*hs);
                   vs++;
                   i++;
                }
                else
                {
                    ans+=(y[j]*vs);
                    hs++;
                    j++;
                }
            }
            else if(i<x.size()){
                 ans+=(x[i]*hs);
                   vs++;
                   i++;
            }
            else
            {
                 ans+=(y[j]*vs);
                    hs++;
                    j++;
            }
        }
        return ans;
    }
};
