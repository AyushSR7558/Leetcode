class Solution {
private:
    double recursion(int a, int b,vector<vector<double>>& dp) {
        if (a <= 0 && b <= 0)
            return 0.5;
        if (a <= 0)
            return 1;
        if (b <= 0)
            return 0;
        if((dp[a][b] != -1)) return dp[a][b];
        return dp[a][b] = (0.25 * (recursion(a - 4, b,dp) + recursion(a - 3, b - 1,dp) +
                       recursion(a - 2, b - 2,dp)+ recursion(a - 1, b - 3,dp)));
    }

public:
    double soupServings(int n) {
        if(n >= 4500) return 1;
        vector<vector<double>> dp((n+24)/25 + 1,vector<double>(n+24/25 + 1,-1));
        return recursion((n + 24)/25,(n + 24)/25,dp);
    }
};