class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // To check for the horizontal cut  we will need the prefix sum for the column wise
        vector<long long> rowwise(m), columnwise(n);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                columnwise[j] += grid[i][j];
                rowwise[i] += grid[i][j];
            }
        }

        for(int i = 1; i < m; i++) {
            rowwise[i] += rowwise[i - 1];
        }

        for(int i = 1; i < n; i++) {
            columnwise[i] += columnwise[i - 1];
        }

        if(rowwise[m - 1] % 2 == 0)
        for(int i = 0; i < m; i++) {
            if(rowwise[i] == rowwise[m - 1] / 2) {
                return true;
            }
        }


        if(columnwise[n - 1] % 2 == 0)
        for(int i = 0; i < n; i++) {
            if(columnwise[i] == columnwise[n - 1] / 2) {
                return true;
            }
        }
        return false;

    }
};