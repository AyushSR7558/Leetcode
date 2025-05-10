class Solution {
private:
    int untill(vector<int>& nums,int target,int ind){
        if(ind == 0){
            if(target == nums[0] && target == -nums[0])return 2;
            if(target == nums[0] || target == -nums[0])return 1;
            return 0;
        }
        int add = untill(nums,target - nums[ind], ind - 1);
        int sub = untill(nums,target + nums[ind], ind - 1);
        return add + sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return untill(nums,target,nums.size() - 1);
    }
};