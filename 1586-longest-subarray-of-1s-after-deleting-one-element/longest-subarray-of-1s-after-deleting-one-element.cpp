class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        // Now we will look at the Greedy plus Sliding window approach
        int maxi = 0; // This will store the ans
        int leftPtr = 0, rightPtr = 0;
        vector<int> freq(2,0);
        while(rightPtr < n) {
            freq[nums[rightPtr++]]++;
            while(leftPtr < n && freq[0] > 1) {
                freq[nums[leftPtr]]--;
                leftPtr++;
            }
            maxi = max(rightPtr - leftPtr - 1, maxi);
        }
        return maxi;
    }
};