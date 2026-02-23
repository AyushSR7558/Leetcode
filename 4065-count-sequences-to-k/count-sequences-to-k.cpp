class Solution {
private:
    long long helper(vector<int>& nums, long long k, unordered_map<string, int>& dp, long long num, long long den, int indx) {
        int n = nums.size();
        if(indx >= n) {
            if(num % den == 0) {
                return (num / den) == k;
            }
            return 0;
        }

        long g = gcd(num, den);
        num /= g;
        den /= g;

        string temp = to_string(num) + "_" + to_string(den) + "_" + to_string(indx);

        if(dp.count(temp)) {
            return dp[temp];
        }



        // Add , Divide, Remain unchanged
        return dp[temp] =  helper(nums, k, dp, num *  nums[indx], den, indx + 1) + helper(nums, k, dp, num, den * nums[indx], indx + 1) + helper(nums, k,dp, num, den, indx + 1);
        }
public:
    int countSequences(vector<int>& nums, long long k) {
        unordered_map<string, int> dp;
        return helper(nums, k, dp, 1, 1, 0);
    }
};