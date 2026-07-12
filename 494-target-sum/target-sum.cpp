class Solution {
private:
    int helper(vector<int>& nums, int target, int indx) {
        if(indx == 0) {
            if(target + nums[indx] == 0 && target - nums[indx] == 0) {
                return 2;
            }
            if(target + nums[indx] == 0 || target - nums[indx] == 0) {
                return 1;
            }
            return 0;
        }

        // Either we can add or sub
        return helper(nums, target + nums[indx], indx - 1) + helper(nums, target - nums[indx], indx - 1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return helper(nums, target, n - 1);
    }
};