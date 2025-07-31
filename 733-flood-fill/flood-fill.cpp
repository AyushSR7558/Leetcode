class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        if (color == image[sr][sc])
            return image;
        int m = image.size(), n = image[0].size();
        int originalCol = image[sr][sc];
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<pair<int, int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        image[sr][sc] = color;
        q.push({sr, sc});
        vis[sr][sc] = true;
        while (!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            int x = temp.first, y = temp.second;
            for (int i = 0; i < 4; i++) {
                if (x + direction[i].first >= 0 && x + direction[i].first < m &&
                    y + direction[i].second >= 0 &&
                    y + direction[i].second < n &&
                    image[x + direction[i].first][y + direction[i].second] ==
                        originalCol &&
                    vis[x + direction[i].first][y + direction[i].second] == false) {
                    image[x + direction[i].first][y + direction[i].second] = color;
                    vis[x + direction[i].first][y + direction[i].second] = true;
                    q.push({x + direction[i].first, y + direction[i].second});
                }
            }
        }
        return image;
    }
};