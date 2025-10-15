class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int prevLen = 0; 
        int curLen = 0;
        
        for (int i = 0; i < n; ++i) {
            ++curLen;
            if (i == n - 1 || nums[i] >= nums[i + 1]) {
                ans = max(ans, curLen / 2);
                ans = max(ans, min(prevLen, curLen));
                
                prevLen = curLen;
                curLen = 0;
            }
        }
        
        return ans;
    }
};
