class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        vector<int>ans(2,0);
        int res=INT_MAX;
        int i=0,j=arr2.size()-1;
        while(i<arr1.size() && j>=0){
            if(abs(arr1[i]+arr2[j]-x)<res){
                res=abs(arr1[i]+arr2[j]-x);
                ans[0]=arr1[i];
                ans[1]=arr2[j];
            }
            else if(arr1[i]+arr2[j]>x){
                j--;
            }
            else i++;
        }
        

        return ans;
    }
};

