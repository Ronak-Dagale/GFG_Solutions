class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int i=0,j=0;
        while(j<arr.size()){
           if(arr[j]!=0){
               arr[i]=arr[j];
               i++;
               j++;
           }
           else
           {
               j++;
           }
        }
        while(i<arr.size()){
            arr[i]=0;
            i++;
        }
    }
};