class Solution {
private:
    long long helper(vector<int>& nums, vector<int>& colors, vector<long long>& dp, int indx) {
        int n = nums.size();

        if(indx >= n) return 0;

        if(indx == n - 1) {
            return nums[indx];
        } 
        if(dp[indx] != -1) return dp[indx];

        long long maxi = LLONG_MIN;
        if(colors[indx] == colors[indx + 1]) {
            maxi = helper(nums, colors, dp, indx + 2) + nums[indx];
        }else {
            maxi = helper(nums, colors, dp, indx + 1) + nums[indx];
        }

        maxi = max(maxi, helper(nums, colors, dp, indx + 1));
        return dp[indx] =  maxi;
    }
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<long long> dp(n, -1);
        return helper(nums, colors, dp, 0);
    }
};