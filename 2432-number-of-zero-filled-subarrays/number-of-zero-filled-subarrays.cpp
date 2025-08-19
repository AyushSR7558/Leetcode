class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        int low = 0;
        while(low < n) {
            while(low < n && nums[low] != 0) {
                low++;
            }
            int subCount = 0;
            while(low < n && nums[low] == 0) {
                count += ++subCount;
                low++;
            }
        }
        return count;
    }
};