class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));


        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // If they are matching take add 1 to dp[i - 1][j - 1]
                if(text1[i] == text2[j]) {
                    dp[i][j] += 1;
                    if(i - 1 >= 0 && j - 1 >= 0) {
                        dp[i][j] += dp[i - 1][j - 1];
                    }
                }else {
                    if(i - 1 >= 0) dp[i][j] = max(dp[i - 1][j], dp[i][j]);
                    if(j - 1 >= 0) dp[i][j] = max(dp[i][j - 1], dp[i][j]);
                }
            }
        }


        return dp[m - 1][n - 1];
    }
};