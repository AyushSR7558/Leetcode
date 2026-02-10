class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto firstit = lower_bound(nums.begin(), nums.end(), target);
        auto lastit = upper_bound(nums.begin(), nums.end(), target);

        if(((lastit == nums.begin())|| firstit == nums.end())) {
            return {-1, -1};
        }
        if(*firstit != target) {
            return {-1, -1};
        }

        return {(int)(firstit - nums.begin()),(int) (lastit - nums.begin() - 1)};
    }
};