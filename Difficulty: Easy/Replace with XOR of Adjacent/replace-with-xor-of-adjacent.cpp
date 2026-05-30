class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        // code here
        int n=arr.size(),prev=arr[0];
        arr[0]=arr[0]^arr[1];
        for(int i=1;i<n-1;i++){
            int tmp=arr[i];
            arr[i]=prev^arr[i+1];
            prev=tmp;
        }
        arr[n-1]=arr[n-1]^prev;
    }
};