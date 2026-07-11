class Solution {
private:
    int helper(vector<int>& coins, int amount, int indx, vector<vector<int>>& dp) {
        if(amount == 0) return 0;

        int m = coins.size();
        if(indx >= m) return 1e9;
        if(dp[amount][indx] != -1) return dp[amount][indx];

        // If we decide to leave the domination of coin
        int minCoinRequired = helper(coins, amount, indx + 1, dp);  


        if(coins[indx] <= amount)
        // If we decide to take the domination of coin
            minCoinRequired = min(1 + helper(coins, amount - coins[indx], indx, dp), minCoinRequired);

        return dp[amount][indx] = minCoinRequired;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // The two factor are changing 
        // We will need the 2D vector for it
        vector<vector<int>> dp(amount + 1, vector<int>(n, -1));
        int res = helper(coins, amount, 0, dp);        
        return (res >= 1e9? -1: res);
    }
};