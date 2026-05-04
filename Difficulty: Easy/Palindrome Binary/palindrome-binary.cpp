class Solution {
  public:
  string toBin(long long int n){
      string res="";
      while(n!=0){
          res.push_back((n&1)+'0');
          n=n/2;
      }
      reverse(res.begin(),res.end());
      return res;
  }
    int isPallindrome(long long int N) {
        // code here
        string bin=toBin(N);
        int i=0,j=bin.size()-1;
        while(i<j){
            if(bin[i]!=bin[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
};