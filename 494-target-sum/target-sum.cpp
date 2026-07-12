class Solution {
private:
    int helper(vector<int>& nums, int target, int indx, unordered_map<string, int>& dp) {
        string key = to_string(target) + "_" + to_string(indx);
        if(indx == 0) {
            if(target + nums[indx] == 0 && target - nums[indx] == 0) {
                return 2;
            }
            if(target + nums[indx] == 0 || target - nums[indx] == 0) {
                return 1;
            }
            return 0;
        }

        if(dp.contains(key)) {
            return dp[key];
        }

        // Either we can add or sub
        return dp[key] = helper(nums, target + nums[indx], indx - 1, dp) + helper(nums, target - nums[indx], indx - 1, dp);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<string, int> dp;
        return helper(nums, target, n - 1, dp);
    }
};