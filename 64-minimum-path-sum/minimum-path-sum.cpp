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
        vector<vector<int>> dp(m, vector<int>(n , -1));
        return helper(grid, m - 1, n - 1, dp);
        
    }
};