class Solution {
private:
    vector<pair<int,int>> dir = {{-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] !=0 || grid[n - 1][n - 1] != 0) return -1;
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        queue<vector<int>> pq;
        dis[0][0] = 1;

        pq.push({1, 0, 0});
        while(!pq.empty()) {
            auto it = pq.front();
            pq.pop();

            int dist = it[0], x = it[1], y = it[2];
            for(int i = 0; i < 8; i++) {
                int nx = x + dir[i].first, ny = y + dir[i].second;
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && (grid[nx][ny] == 0)) {
                    int ndist = dist + 1;
                    if(dis[nx][ny] > ndist) {
                        dis[nx][ny] = ndist;
                        pq.push({ndist, nx, ny});
                    }
                }
            }
        }
        return (dis[n -1][n -1] == INT_MAX? -1: dis[n - 1][n -1]);
    }
};