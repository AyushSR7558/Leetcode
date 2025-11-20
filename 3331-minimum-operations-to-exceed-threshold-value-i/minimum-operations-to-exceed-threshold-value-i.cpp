class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return distance(nums.begin(), lower_bound(nums.begin(),nums.end(),k));
    }
};