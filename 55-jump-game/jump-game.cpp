class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIndx = nums[0];

        for(int i = 0; i <= maxIndx && i < n; i++) {
            maxIndx = max(maxIndx, nums[i] + i);
        }

        return maxIndx >= n - 1; 
    }
};