class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> maxDist(n);
        vector<bool> ans;
        maxDist[n - 1] = n - 1;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i + 1] - nums[i] <= maxDiff) {
                maxDist[i] = maxDist[i + 1];
            }else {
                maxDist[i] = i;
            }
        }

        for(int i = 0; i < m; i++) {
            int l = min(queries[i][0], queries[i][1]), r = max(queries[i][0], queries[i][1]);

            if(maxDist[l] >= r) {
                ans.push_back(true);
            }else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};