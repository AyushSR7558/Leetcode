class Solution {
private:
    vector<pair<int,int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        dis[0][0] = 0;

        pq.push({0, 0, 0});
        while(!pq.empty()) {
            auto it = pq.top();
            int dist = it[0], x = it[1], y = it[2];
            pq.pop();
            if(dist > dis[x][y]) continue;

            for(int i = 0; i < dir.size(); i++) {
                int nx = x + dir[i].first , ny = y + dir[i].second;
                if(!(nx >=0 && nx < m && ny >= 0 && ny < n)) continue;
                int ndist = max(dist, abs(heights[x][y] - heights[nx][ny]));
                if(ndist < dis[nx][ny]) {
                    pq.push({ndist, nx, ny});
                    dis[nx][ny] = ndist;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cout << dis[i][j] <<  " ";
            }
            cout << endl;
        }
        return dis[m - 1][n - 1];
    }
};