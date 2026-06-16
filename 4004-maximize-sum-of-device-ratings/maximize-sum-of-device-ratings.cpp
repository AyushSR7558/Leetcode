class Solution {
private:
    // function to get first minimum and second minimum
    pair<int, int> getMinimum(vector<int>& nums) {
        int n = nums.size();
        int first = INT_MAX, second = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(nums[i] < first) {
                second = first;
                first = nums[i];
            }else if(nums[i] < second) {
                second = nums[i];
            }
        }

        return {first, second};
    }
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size(), n = units[0].size();

        if(n == 1) {
            long long rating = 0;
            for(int i = 0; i < m; i++) rating += units[i][0];
            return rating;
        }
        vector<pair<int, int>> mini;

        for(int i = 0; i < m; i++) {
            mini.push_back(getMinimum(units[i]));
        }

        long long rating = 0, val = INT_MAX, val1 = INT_MAX;
        
        for(int i = 0; i < m; i++) {
            rating += mini[i].second;
            val = min((int)val, mini[i].first);
            val1 = min((int)val1, mini[i].second);
        }

        if(val == INT_MAX) return rating;

        return rating - val1 + val;

    }
};