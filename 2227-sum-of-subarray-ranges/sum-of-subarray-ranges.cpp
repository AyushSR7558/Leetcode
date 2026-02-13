class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size(); // Size of the nums
        long long sum = 0; // This will store the sum over all the subarray

        for(int i = 0; i < n; i++) {
            int maxi = nums[i], mini = nums[i];
            for(int j = i; j < n; j++) {
                maxi = max(maxi, nums[j]);
                mini = min(mini, nums[j]);
                sum += maxi - mini;
            }
        }

        return sum;
    }
};