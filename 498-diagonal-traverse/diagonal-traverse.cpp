class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> nums;
        nums.reserve(m * n); // \U0001f680 avoid reallocations

        // Use vector instead of map (since keys are 0..m+n-2)
        vector<vector<int>> diag(m + n - 1);

        // Fill diagonals
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diag[i + j].push_back(mat[i][j]);
            }
        }

        // Traverse diagonals
        for (int d = 0; d < m + n - 1; d++) {
            if (d % 2 == 0) {
                // reverse order push
                nums.insert(nums.end(), diag[d].rbegin(), diag[d].rend());
            } else {
                nums.insert(nums.end(), diag[d].begin(), diag[d].end());
            }
        }

        return nums;
    }
};
