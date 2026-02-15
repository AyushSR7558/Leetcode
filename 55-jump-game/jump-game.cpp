class Solution {
private:
    bool helper(vector<int>& nums, int indx, vector<int>& dp) {
        int n = nums.size();
        if(indx >= n - 1) return true;
        if(dp[indx] != -1) return dp[indx];

        for(int i = indx + 1; i < n && i <= indx + nums[indx]; i++) {
            if(helper(nums, i, dp)) {
                return dp[indx] = true;
            }
        }

        return dp[indx] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(nums, 0, dp);
    }
};