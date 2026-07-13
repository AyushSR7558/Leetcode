class Solution {
private:
    int helper(string& text1, string& text2, int indx1, int indx2, vector<vector<int>>& dp) {
        if(indx1 < 0 || indx2 < 0) return 0;
        if(dp[indx1][indx2] != -1) return dp[indx1][indx2];

        if(text1[indx1] == text2[indx2]) return dp[indx1][indx2] = 1 + helper(text1, text2, indx1 - 1, indx2 - 1, dp);

        return dp[indx1][indx2] = max(helper(text1,text2, indx1 - 1, indx2, dp), helper(text1, text2, indx1, indx2- 1, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(text1, text2, m - 1, n - 1, dp);
        
    }
};