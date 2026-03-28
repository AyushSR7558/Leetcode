class Solution {
public:
    long long ans = 0;

    pair<long long, long long> dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& price) {
        long long withLeaf = price[u];
        long long withoutLeaf = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;

            auto [childWith, childWithout] = dfs(v, u, adj, price);

            ans = max(ans, withLeaf + childWithout);
            ans = max(ans, withoutLeaf + childWith);

            withLeaf = max(withLeaf, childWith + price[u]);
            withoutLeaf = max(withoutLeaf, childWithout + price[u]);
        }

        return {withLeaf, withoutLeaf};
    }

    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, adj, price);

        return ans;
    }
};