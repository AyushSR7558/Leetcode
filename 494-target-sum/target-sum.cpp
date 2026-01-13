class Solution {
private:
    int helper(vector<int>& nums, int target, int indx) {
        // Base case 
        if(indx == 0) {
            if(nums[0] == 0 && target == 0) return 2;
            if(target + nums[indx] == 0 || target - nums[indx] == 0) return 1;
            return 0;
        }

        int count = helper(nums, target -nums[indx], indx -1) + helper(nums, target + nums[indx], indx - 1);

        return count;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        return helper(nums, target, n);
    }
};