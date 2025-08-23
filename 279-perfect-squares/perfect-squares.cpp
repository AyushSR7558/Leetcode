class Solution {
private:
    int Minimize(int n, int indx,vector<vector<int>>&dp) {
        // Bases cases
        if(n == 0) return 0;
        if(indx * indx > n) return 1e4;
        if(dp[n][indx] != -1) return dp[n][indx];


        // First Case
        int notTake = 1e4, Take = 1e4;

        notTake = Minimize(n , indx + 1, dp);

        if(n >= indx * indx) {
            Take = 1 + Minimize(n - indx * indx, indx, dp);
        }
        return dp[n][indx] = min(notTake,Take);
    }
public:
    int numSquares(int n) {
        int x = sqrt(n);
        vector<vector<int>>dp(n + 1, vector<int>(x + 1, -1));
        return Minimize(n,1,dp);
    }
};