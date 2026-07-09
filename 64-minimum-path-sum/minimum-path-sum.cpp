class Solution {
private:
    int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        // The function will return maximum we can get if we are at the ceil {i, j}
        if(i < 0 || j < 0) return 1e9 + 7;
        if(i == 0 && j == 0) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = min(grid[i][j] + helper(grid, i - 1, j, dp), grid[i][j] + helper(grid, i, j - 1, dp));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n , 1e9));
        dp[0][0] = grid[0][0];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue;
                if(i - 1 >= 0) {
                    dp[i][j] = min(dp[i][j], grid[i][j] + dp[i - 1][j]);
                }
                if(j - 1 >= 0) {
                    dp[i][j] = min(dp[i][j], grid[i][j] + dp[i][j - 1]);
                }

            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[m - 1][n - 1];
        
    }
};