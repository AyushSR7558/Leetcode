class Solution {
    vector<pair<int,int>> direction = {{1,0},{0,-1},{-1,0},{0,1}};
    
private:
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int t) {
        int n = grid.size();
        if(x < 0 || x >= n || y < 0 || y >= n || visited[x][y] || grid[x][y] > t) 
            return false;
        if(x == n-1 && y == n-1) return true;
        
        visited[x][y] = true;
        for(auto a : direction){
            int newX = x + a.first, newY = y + a.second;
            if(dfs(grid, visited, newX, newY, t))
                return true;
        }
        return false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = grid[0][0], right = n * n - 1, ans = right;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            vector<vector<bool>> visited(n, vector<bool>(n,false));
            if(dfs(grid, visited, 0, 0, mid)){
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
