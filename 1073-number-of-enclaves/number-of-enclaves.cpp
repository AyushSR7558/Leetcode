class Solution {
    int m , n;
    int dirX[4] = {-1,0,1,0};
    int dirY[4] = {0,1,0,-1};
private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int x, int y){
        if(x < 0 || x >= m || y < 0 || y >= n ) return ;
        if(grid[x][y] == 0) return ;
        if(vis[x][y]) return ;

        vis[x][y] = true;
        for(int i = 0; i < 4; i++){
            int nx = x + dirX[i];
            int ny = y + dirY[i];
            dfs(grid,vis,nx,ny);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1){
                dfs(grid,vis,i,0);
            }
            if(grid[i][n -1] == 1){
                dfs(grid,vis,i,n-1);
            }
        }
        for(int i = 0; i < n; i++){
            if(grid[0][i] == 1){
                dfs(grid,vis,0,i);
            }
            if(grid[m - 1][i] == 1){
                dfs(grid,vis,m-1,i);
            }
        }
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && vis[i][j] == false){
                    count++;
                }
            }
        }
        return count;
    }
};