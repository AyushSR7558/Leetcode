class Solution {
private:
    int helper(vector<int>& nums, int indx, vector<int>& dp) {
        if(indx == 0) return nums[indx];
        if(indx < 0) return 0;
        if(dp[indx] != -1) return dp[indx];

        int pick = nums[indx] + helper(nums, indx - 2, dp);
        int notPick = helper(nums, indx - 1,dp);
        return dp[indx] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums, nums.size() - 1, dp);
    }
};