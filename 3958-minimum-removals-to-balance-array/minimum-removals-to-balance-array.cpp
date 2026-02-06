class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int minRemoval = INT_MAX;

        while(r < n){
            while(r < n && (nums[r] + k - 1) / k <= nums[l]) {
                r++;
            }
            minRemoval = min(minRemoval, n - r + l);
            l++;
        }
        return minRemoval;
    }
};