class Solution {
public:
    vector<vector<int>> dp;
    const int INF = 1e9;

    int solve(vector<int>& cost, int id, int rem) {
        if (rem == 0) return 0;
        if (id >= cost.size()) return INF;

        if (dp[id][rem] != -1)
            return dp[id][rem];

        int notTake = solve(cost, id + 1, rem);

        int take = INF;
        int wt = id + 1;

        if (cost[id] != -1 && rem >= wt) {
            take = cost[id] + solve(cost, id, rem - wt);
        }

        return dp[id][rem] = min(take, notTake);
    }

    int minimumCost(vector<int>& cost, int w) {
        int n = cost.size();

        dp.assign(n, vector<int>(w + 1, -1));

        int ans = solve(cost, 0, w);

        return (ans >= INF) ? -1 : ans;
    }
};