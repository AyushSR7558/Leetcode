class Solution {
public:
    int finalElement(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1) return nums[0];
        return max(nums[0], nums[n - 1]);
    }
};