class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int ans=0,s=0,e=arr.size()-1;
        if(arr[e]>arr[0]) return 0;
        while(s<e){
            int mid=s+(e-s)/2;;
            if(arr[mid]>arr[e]){
                s=mid+1;
            }
            else
            e=mid;
        }
        return s;
    }
};
