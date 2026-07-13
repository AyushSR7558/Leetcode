class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);

            for (int j = 0; j < n; j++) {
                // If they are matching take add 1 to dp[i - 1][j - 1]
                if (text1[i] == text2[j]) {
                    curr[j] += 1;
                    if (j - 1 >= 0) {
                        curr[j] += prev[j - 1];
                    }
                } else {
                    curr[j] = prev[j];
                    if (j - 1 >= 0)
                        curr[j] = max(curr[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};