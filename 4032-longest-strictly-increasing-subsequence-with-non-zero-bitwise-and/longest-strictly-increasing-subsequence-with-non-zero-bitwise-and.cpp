class Solution {
private:
    int LIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;

        for(int i = 0; i < n; i++) {
            auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
            if(it == temp.end()) {
                temp.push_back(nums[i]);
            }else {
                *it = nums[i];
            }
        }
        return temp.size();
    }
public:
    int longestSubsequence(vector<int>& nums) {
        vector<vector<int>> mp(31);

        for(int i = 0; i < 31; i++) {
            for(int j = 0; j < nums.size(); j++) {
                if(nums[j] & (1 << i)) {
                    mp[i].push_back(nums[j]);
                }
            }
        }

        int maxi = 0;

        for(int i = 0; i < 31; i++) {
            maxi = max(maxi, LIS(mp[i]));
        }
        return maxi;
        
    }
};