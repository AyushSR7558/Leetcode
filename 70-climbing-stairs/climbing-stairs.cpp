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
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};