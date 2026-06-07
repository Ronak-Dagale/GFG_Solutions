class Solution {
  public:
    string profession(int level, int pos) {
        // code here
        if(pos==1) return "Engineer";
        
        if(profession(level-1,(pos+1)/2)=="Engineer"){
            if(pos%2==1) return "Engineer";
            else return "Doctor";
        }
        else{
            if(pos%2==1) return "Doctor";
            else return "Engineer";
        }
    }
};