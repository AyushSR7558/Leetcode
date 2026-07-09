class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;


        vector<vector<bool>> dp(n, vector<bool>(sum + 1, true));

        for(int i = 1; i <= sum; i++)  dp[0][i] = false;

        dp[0][nums[0]] = true;

        for(int i = 1; i < n; i++) {
            for(int t = 1; t <= sum; t++) {
                bool notTake = dp[i - 1][t], take = false;
                if(nums[i] <= t) {
                    take = dp[i - 1][t - nums[i]];
                }
                dp[i][t] = take || notTake;
            }
        }


        return dp[n - 1][sum / 2];
        
    }
};