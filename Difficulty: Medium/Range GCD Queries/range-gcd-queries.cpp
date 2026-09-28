class Solution {
  public:
   vector<int> tree;

       void build(vector<int>& arr, int node, int l, int r) {
           if (l == r) {
               tree[node] = arr[l];
               return;
           }

           int mid = l + (r - l) / 2;

           build(arr, 2 * node, l, mid);
           build(arr, 2 * node + 1, mid + 1, r);

           tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
       }

       void update(int node, int l, int r, int index, int value) {
           if (l == r) {
               tree[node] = value;
               return;
           }

           int mid = l + (r - l) / 2;

           if (index <= mid) {
               update(2 * node, l, mid, index, value);
           } else {
               update(2 * node + 1, mid + 1, r, index, value);
           }

           tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
       }

       int query(int node, int l, int r, int ql, int qr) {
           if (qr < l || r < ql)
               return 0;

           if (ql <= l && r <= qr)
               return tree[node];

           int mid = l + (r - l) / 2;

           return gcd(
               query(2 * node, l, mid, ql, qr),
               query(2 * node + 1, mid + 1, r, ql, qr)
           );
       }

   public:
       vector<int> processQueries(vector<int>& arr, vector<vector<int>>& queries) {
           int n = arr.size();

           tree.resize(4 * n);
           build(arr, 1, 0, n - 1);

           vector<int> ans;

           for (auto& q : queries) {
               if (q[0] == 0) {
                   ans.push_back(query(1, 0, n - 1, q[1], q[2]));
               } else {
                   update(1, 0, n - 1, q[1], q[2]);
               }
           }

           return ans;
       }
};