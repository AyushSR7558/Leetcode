class Solution {
private:
    long long solve(vector<int>& nums, int trend, int indx, vector<vector<long long>>& dp) {
        int n = nums.size();
        if(indx == n) {
            if(trend == 3) {
                return 0;
            }else {
                return LLONG_MIN/2;
            }
        }
        if(dp[indx][trend] != -1) return dp[indx][trend];

        long long take = LLONG_MIN/2;
        long long skip = LLONG_MIN/2;

        if(trend == 0) {
            skip = solve(nums, 0, indx + 1, dp);
        }

        if(trend == 3) {
            take = nums[indx];
        }

        if(indx + 1 < n){
            long long curr = nums[indx], next = nums[indx + 1];
            if(trend == 0 && next > curr) {
                take = max(take, curr + solve(nums, 1, indx + 1, dp));
            }else if(trend == 1) {
                if((next > curr)) {
                    take = max(take, curr + solve(nums, 1, indx + 1, dp));
                }else if(next < curr) {
                    take = max(take, curr + solve(nums, 2, indx + 1, dp));
                }
            }else if(trend == 2) {
                if(next > curr) {
                    take = max(take, curr + solve(nums, 3, indx + 1, dp));
                }else if(next < curr) {
                    take = max(take, curr + solve(nums, 2, indx + 1, dp));
                }
            }else if(trend == 3 && next > curr) {
                take = max(take,curr + solve( nums, 3, indx + 1, dp));
            }
        }


        return dp[indx][trend] = max(take, skip);
    }
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(4, -1));
        return solve(nums, 0, 0, dp);
        
    }
};