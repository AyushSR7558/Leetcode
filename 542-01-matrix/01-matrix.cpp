class Solution {
public : vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> ans(m, vector<int>(n, 0));
        queue < pair<pair<int, int>, int>>q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    visited[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }
        vector<pair<int, int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while (!q.empty()) {
            int x = q.front().first.first, y = q.front().first.second;
            int distance = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + direction[i].first, ny = y + direction[i].second;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    visited[nx][ny] == false) {
                    q.push({{nx, ny}, distance + 1});
                    visited[nx][ny] = true;
                    ans[nx][ny] = distance + 1;
                }
            }
        }
        return ans;
    }
};