class Solution {
private:
    int helper(int i, int j, vector<int>& nums) {
        if(i  > j) return 0;

        if(i == j) return nums[i];

        int leftDiff = nums[i] - helper(i + 1, j, nums);
        int rightDiff = nums[j] - helper(i,j - 1, nums);

        return max(leftDiff, rightDiff);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        return helper(0, nums.size() - 1, nums) >= 0;
    }
};