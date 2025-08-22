class Solution {
private:
    int solve(vector<int>& jobDifficulty,int n, int d, int indx,vector<vector<int>> & dp) {
        if(dp[indx][d] != -1) return dp[indx][d];
        if(d == 1) {
            int maxD = jobDifficulty[indx];
            for(int i = indx; i < n; i++) {
                maxD = max(maxD, jobDifficulty[i]);
            }
            return maxD;
        }
        int maxD = jobDifficulty[indx];
        int finalResult = INT_MAX;
        for(int i = indx; i <= n - d; i++) {
            maxD = max(maxD, jobDifficulty[i]);
            int result = maxD + solve(jobDifficulty,n,d - 1, i + 1,dp);
            finalResult = min(finalResult,result);
        }
        return dp[indx][d] = finalResult;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, -1));
        if(n < d) {
            return -1;
        }
        return solve(jobDifficulty, n, d, 0,dp);
    }
};