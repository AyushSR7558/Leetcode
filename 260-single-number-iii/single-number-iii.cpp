class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i += 2) {
            if (nums[i] != nums[i - 1]) {
                ans.push_back(nums[i - 1]);
                i-=1;
            }
        }
        if(ans.size()!=2) ans.push_back(nums[n-1]);
        return ans;
    }
};