class Solution {
private:
    int helper(string& s1, string& s2, int x, int y, vector<vector<int>>& dp) {
        if(x < 0 || y < 0) {
            int count = 0;
            for(int i = x; i >= 0; i--) {
                count += s1[i];
            }
            for(int i = y; i >= 0; i--) {
                count += s2[i];
            }
            return count;
        }

        if(dp[x][y] != -1) return dp[x][y];
        // There are two possibility One if both are equal or if both are different
        if(s1[x] == s2[y]) {
            return helper(s1, s2, x - 1, y - 1, dp);
        }

        // If both does not have the same char at that indx then we have another two ways
        int mini = min((int)(s1[x]) + helper(s1, s2, x - 1, y, dp), (int)(s2[y]) + helper(s1, s2, x, y - 1, dp));

        return dp[x][y] = mini;
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp (s1.size(), vector<int>(s2.size(), -1));
        return helper(s1, s2, s1.size() - 1, s2.size() - 1, dp);
    }
};