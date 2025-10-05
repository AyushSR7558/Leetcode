class Solution {
private:    
        void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        visited[i][j] = true;
        
        for (auto& d : directions) {
            int x = i + d[0], y = j + d[1];
            
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (visited[x][y]) continue;
            if (heights[x][y] < heights[i][j]) continue;
            
            dfs(x, y, heights, visited);
        }
    }
public:
    int m, n;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> vPacific(m, vector<bool>(n, false));
        vector<vector<bool>> vAtlantic(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) dfs(i, 0, heights, vPacific);
        for(int i = 0; i < n; i++) dfs(0, i, heights, vPacific);

        for(int i = 0; i < m; i++) dfs(i, n - 1, heights, vAtlantic);
        for(int i = 0; i < n; i++) dfs(m - 1, i, heights, vAtlantic);

        vector<vector<int>> ans;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(vPacific[i][j] && vAtlantic[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }

};