class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        int n = nums.size(), ans = 0, sum = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
             sum = sum + nums[i];
            int diff = sum - goal;
            if (mp.find(diff) != mp.end()) {
                ans += mp[diff];
            }
            mp[sum]++;
        }
        for (auto &[k,p]: mp) {
            cout << k << " " << p;
        }
        return ans;
    }
};