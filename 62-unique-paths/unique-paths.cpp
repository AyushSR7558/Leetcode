class Solution {
private:
   int helper(int m, int n, int i, int j, vector<vector<int>>& dp) {
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = helper(m, n, i - 1, j, dp) + helper(m, n, i, j - 1, dp);
   }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n , - 1));
        return helper(m, n, m - 1, n - 1, dp);
        
    }
};