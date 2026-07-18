class Solution {
private:
    int helper(string& s, string& t, int t1, int t2, vector<vector<int>>& dp) {
        if(t2 < 0) return 1;
        if(t1 < 0) return 0;
        if(dp[t1][t2] != -1) return dp[t1][t2];

        int cnt = 0;
        if (s[t1] == t[t2]) {
            cnt += helper(s, t, t1 - 1, t2 - 1, dp);
        }
        cnt += helper(s, t, t1 - 1, t2, dp);
        return dp[t1][t2] = cnt;
    }
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(s, t, m - 1, n - 1, dp);
        
    }
};