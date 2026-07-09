class Solution {
private:
    int helper(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp) {
        // If we are ceil {i, j} what is the min value that we can get if we start from that ceil
        int m = triangle.size(), n = i + 1; 

        // Base case
        if(i == m - 1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = triangle[i][j] + min(helper(triangle, i + 1, j, dp), helper(triangle, i + 1, j + 1, dp));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for(int i = 0; i < m; i++) {
            dp[m - 1][i] = triangle[m - 1][i];
        }
        
        for(int i = m - 2; i >= 0; i--) {
            for(int j = 0; j < i + 1; j++) {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
};