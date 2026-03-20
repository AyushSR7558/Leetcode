class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int limitrow = m - k + 1;
        int limitcol = n - k + 1;
        vector<vector<int>> ans(limitrow, vector<int>(limitcol, 0)); 

        for (int i = 0; i < limitrow; i++) {
        for (int j = 0; j < limitcol; j++) {
            vector<int> block;
            block.reserve(k * k);
            for (int di = 0; di < k; di++) {
                for (int dj = 0; dj < k; dj++) {
                    block.push_back(grid[i + di][j + dj]);
                }
            }
            sort(block.begin(), block.end());

            int minDiff = INT_MAX;
            for (int idx = 1; idx < (int)block.size(); idx++) {
                if(block[idx] == block[idx - 1])continue;
                minDiff = min(minDiff,abs(block[idx] - block[idx - 1]));
            }
            if (minDiff == INT_MAX) {
                minDiff = 0;
            }
            ans[i][j] = minDiff;
        }
    }

    return ans;
    }
};