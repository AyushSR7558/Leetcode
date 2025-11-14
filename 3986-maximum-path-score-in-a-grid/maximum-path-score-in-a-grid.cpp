class Solution {
    int m, n;
    vector<pair<int, int>> dir = {{1,0}, {0,1}};
    vector<int> cost = {0,1,1};
    vector<int> reward = {0, 1, 2};
private:    
    int solver(vector<vector<int>>& grid, int x, int y, int k, vector<vector<vector<int>>>& dp) {
        if(k < 0) return INT_MIN;
        
        if(x == m - 1 && y == n - 1) {
            return 0;
        }

        if(dp[x][y][k] != -1) return dp[x][y][k];

        int best = INT_MIN;

        for(int i = 0; i < 2; i++) {
            int newX = x + dir[i].first, newY = y + dir[i].second;

            // Move Down
            if(newX < m && newY < n)
                best = max(best, reward[grid[newX][newY]] + solver(grid, newX, newY, k - cost[grid[newX][newY]], dp));

        }
        return dp[x][y][k] = best;
    }
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        int fVal = solver(grid, 0, 0, k, dp);
        return (fVal < 0? -1: fVal); 
    }
};