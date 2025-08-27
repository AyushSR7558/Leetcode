class Solution {
    vector<pair<int, int>> dirs = {{1,1},{1,-1},{-1,-1},{-1,1}};
    int dp[1005][1005][8];  // compressed DP: i, j, mask (dir<<1 | canTurn)
    int m, n;
    
    int dfs(vector<vector<int>>& grid, int i, int j, int d, int canTurn, int target) {
        i += dirs[d].first;
        j += dirs[d].second;

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != target) 
            return 0;

        int mask = (d << 1) | canTurn;
        int &res = dp[i][j][mask];
        if (res != -1) return res;

        int ans = dfs(grid, i, j, d, canTurn, 2 - target); // continue same dir

        if (canTurn) {
            // theoretical max steps in new dir
            int maxs[4] = {m - i - 1, j, i, n - j - 1};
            int nd = (d + 1) % 4;
            if (maxs[nd] > ans) { 
                ans = max(ans, dfs(grid, i, j, nd, 0, 2 - target));
            }
        }
        return res = ans + 1;
    }

public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1) continue;

                int maxs[4] = {m - i, j + 1, i + 1, n - j};
                for (int d = 0; d < 4; d++) {
                    if (maxs[d] > ans) {
                        ans = max(ans, 1 + dfs(grid, i, j, d, 1, 2));
                    }
                }
            }
        }
        return ans;
    }
};
