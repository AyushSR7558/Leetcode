class Solution {
private:
    int helper(int n, vector<int>& dp) {
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];

        int cnt = helper(n - 1, dp);

        if(n >= 2) cnt += helper(n - 2, dp);
        return dp[n] = cnt;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for(int i = 1; i <= n; i++) {
            dp[i] += dp[i - 1];
            if(i >= 2) dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};