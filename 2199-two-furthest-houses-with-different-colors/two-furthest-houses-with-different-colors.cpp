class Solution {
private:
    int helper(vector<int>& colors, int x, int y, vector<vector<int>>& dp) {
        if(x >= y) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        if(colors[x] != colors[y]) return y - x;
        return dp[x][y] = max(helper(colors, x + 1, y, dp), helper(colors, x, y - 1, dp));
    }
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int dist = helper(colors, 0, n - 1, dp);
        return dist;
    }
};