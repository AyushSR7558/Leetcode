class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dir = {{-1, 0, 1}, {-1, -1, 0}, {0, -1, 1}, {0, 0, 1}};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int temp = 0;
                for(int k = 0; k < 4; k++) {
                    int nx = i + dir[k][0], ny = j + dir[k][1];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && dir[k][2]) {
                        temp += grid[nx][ny];
                    }
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && !dir[k][2]) {
                        temp -= grid[nx][ny];
                    }
                }
                grid[i][j] = temp;
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] <= k) cnt++;
            }
        }
        return cnt;

    }
};