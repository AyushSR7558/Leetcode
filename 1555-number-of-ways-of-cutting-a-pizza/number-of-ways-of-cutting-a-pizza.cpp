class Solution {
private:
    int MOD = 1e9 + 7;
    vector<vector<int>> createSpecialMatrix(vector<string>& pizza) {
        int m = pizza.size(), n = pizza[0].size();
        vector<vector<int>> countApple(m, vector<int>(n, 0));
        for (int i = m - 1; i >= 0; i--) {               // rows
            for (int j = n - 1; j >= 0; j--) {           // cols
                countApple[i][j] = (pizza[i][j] == 'A'); // base case

                if (i + 1 < m)
                    countApple[i][j] += countApple[i + 1][j]; // down
                if (j + 1 < n)
                    countApple[i][j] += countApple[i][j + 1]; // right
                if (i + 1 < m && j + 1 < n)
                    countApple[i][j] -=
                        countApple[i + 1][j + 1]; // avoid double-count
            }
        }
        return countApple;
    }
    bool checker(vector<vector<int>>& spe, int k, int stRow, int edRow,
                 int stCol, int edCol) {
        if (spe[stRow][stCol] - spe[edRow][edCol] >= k)
            return true;
        return false;
    }
    int helper(vector<string>& pizza, vector<vector<int>>& sep, int m, int n,
               int k, int stRow, int stCol, vector<vector<vector<int>>>& dp) {
        if (k == 1) {
            if (sep[stRow][stCol] >= 1) {
                return 1;
            }
            return 0;
        }
                if(dp[stRow][stCol][k] != -1) return dp[stRow][stCol][k];
        long long count = 0;
        // Horizontal Cuts
        for (int i = stRow + 1; i < m; i++) {
            if (checker(sep, 1, stRow, i, stCol, stCol) &&
                sep[i][stCol] >= k - 1) {
                count += helper(pizza, sep, m, n, k - 1, i, stCol,dp) % MOD;
            }
        }
        for (int i = stCol + 1; i < n; i++) {
            if (checker(sep, 1, stRow, stRow, stCol, i) &&
                sep[stRow][i] >= k - 1) {
                count += helper(pizza, sep, m, n, k - 1, stRow, i,dp) % MOD;
            }
        }
        return dp[stRow][stCol][k] = count % MOD;
    }

public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size(), n = pizza[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1 , -1)));
        vector<vector<int>> countApple = createSpecialMatrix(pizza);
        return helper(pizza, countApple, m, n, k, 0, 0,dp);
    }
};