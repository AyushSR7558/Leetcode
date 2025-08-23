class Solution {
private:
    int helper(int n, vector<int>& dp) {
        if(n == 0) return 0;
        if(dp[n]!= -1) return dp[n];
        int mini = n;
        for(int i = 1; i * i <= n; i++) {
            mini = min(1 + helper(n - i * i,dp), mini);
        }
        return dp[n] = mini;
    }
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return helper(n,dp);
    }
};