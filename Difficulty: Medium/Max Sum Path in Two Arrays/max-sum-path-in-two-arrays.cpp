class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        int ans=0;
        int i=0,j=0,sum1=0,sum2=0;
        int m=a.size(),n=b.size();
        
        while(i<m || j<n){
            if(i<m && j<n){
              if(a[i]==b[j]){
                  ans=ans+max(sum1,sum2)+a[i];
                  i++;
                  j++;
                  sum1=0,sum2=0;
              } 
              else if(a[i]<b[j]){
                  sum1=sum1+a[i];
                  i++;
              }
              else{
                  sum2=sum2+b[j];
                  j++;
              }
            }
            else if(i<m){
               sum1=sum1+a[i];
               i++;
            }
            else{
                sum2=sum2+b[j];
                j++;
            }
        }
        ans=ans+max(sum1,sum2);
        return ans;
    }
};