class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int node, int mask, vector<vector<int>>& cost) {
        if (mask == (1 << n) - 1) {
            return cost[node][0];  // return to start
        }

        if (dp[node][mask] != -1)
            return dp[node][mask];

        int res = INT_MAX;

        for (int nxt = 0; nxt < n; nxt++) {
            if (!(mask & (1 << nxt)) && cost[node][nxt] != 0) {
                int newMask = mask | (1 << nxt);
                res = min(res,
                          cost[node][nxt] + solve(nxt, newMask, cost));
            }
        }
        return dp[node][mask] = res;
    }

    int tsp(vector<vector<int>>& cost) {
        n = cost.size();
        int maxMask = 1 << n;

        dp.assign(n, vector<int>(maxMask, -1));

        return solve(0, 1, cost);  // start from 0 with mask = 1
    }
};
