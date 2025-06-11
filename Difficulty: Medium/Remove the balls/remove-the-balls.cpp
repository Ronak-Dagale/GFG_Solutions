class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
          stack<pair<int,int>> st;
        for(int i = 0; i < color.size(); i++)
        {
            if(st.size() > 0 and  st.top().first == color[i] and st.top().second == radius[i])
            {
                st.pop();
                //st_radius.pop();
            }
            else
            {
                st.push({color[i], radius[i]});
            }
        }
        
        return st.size();
    }
};