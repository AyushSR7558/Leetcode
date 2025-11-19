class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        unordered_set<int> mp;
        for(int i = 0; i < n; i++) mp.insert(nums[i]);
        while(mp.count(original)) {
            original = original * 2;
        }
        return original;
    }
};