// class Solution {
// private:
//     int minCoin(vector<int>&coins,int amount,int index,vector<vector<int>>&dp){
//         if(amount == 0)return 0;
//         if(index == 0){
//             if(amount % coins[0])return 1e5;
//             return amount/coins[0];
//         }
//         if(dp[index][amount] != -1)return dp[index][amount];
//         int not_take = minCoin(coins,amount,index - 1,dp);
//         int take = 1e5;
//         if(coins[index] <= amount){
//             take = 1 + minCoin(coins, amount - coins[index], index,dp);
//         }
//         return dp[index][amount] = min(take,not_take);
//     }
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         vector<vector<int>>dp(coins.size(),vector<int>(amount + 1, -1));
//         int x = minCoin(coins,amount,coins.size() - 1,dp);
//         if(x > 1e4)return -1;
//         return x;
//     }
// };
class Solution{
public:
    int coinChange(vector<int>&coins, int amount){
        vector<vector<int>>dp(coins.size(),vector<int>(amount + 1));
        for(int i = 0; i <= amount; i++){
            if(i % coins[0]){
                dp[0][i] = 1e5;
            }else{
                dp[0][i] = i / coins[0];
            }
        }
        for(int i = 1; i < coins.size(); i++){
            for(int j = 1; j <= amount; j++){
                int not_take = dp[i - 1][j];
        int take = 1e5;
        if(coins[i] <= j){
            take = 1 + dp[i][j - coins[i]];
        }
        dp[i][j] = min(take,not_take);
            }
        }
        int x = dp[coins.size() - 1][amount];
        if(x >= 1e5)return -1;
        return x;
    }

};