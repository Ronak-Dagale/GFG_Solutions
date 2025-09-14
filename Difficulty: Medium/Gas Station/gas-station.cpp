class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int n=gas.size(),s=0,balance=0,deficiency=0;
        for(int i=0;i<n;i++){
            balance+=(gas[i]-cost[i]);
            if(balance<0){
                deficiency+=balance;
                s=i+1;
                balance=0;
            }
        }
        if(balance+deficiency>=0) return s;
        return -1;
    }
};