class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0, count = 0;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if(mp[nums[i]]  > count) {
                ans = mp[nums[i]];
                count = mp[nums[i]];
            }else if(mp[nums[i]] == count) {
                ans += mp[nums[i]];
            }
        }
        return ans;
    }
};