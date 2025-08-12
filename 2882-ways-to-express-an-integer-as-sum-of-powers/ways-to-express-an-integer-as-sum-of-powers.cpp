class Solution {
private:
    int MOD = 1e9 + 7;
    int power(int base, int exp) {
        int result = 1;
        for(int i = 0; i < exp; i++) result *= base;
        return result;
    }

    int recursion(int x, int indx, int n, vector<vector<int>>& dp) {
        if(n == 0) return 1;
        int nums = power(indx, x);
        if(nums > n) return 0;
        
        if(dp[indx][n] != -1) return dp[indx][n];

        // Include indx^x
        int include = recursion(x, indx + 1, n - nums, dp);
        // Exclude indx^x
        int exclude = recursion(x, indx + 1, n, dp);

        return dp[indx][n] = (include % MOD + exclude % MOD) % MOD;
    }

public:

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return recursion(x, 1, n, dp) % MOD;
    }
};
