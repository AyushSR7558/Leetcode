class Solution {
private:
    int dfs(vector<vector<int>>& bombs, vector<bool>& isVisited, int u) {
        int n = bombs.size();
        isVisited[u] = true;
        int cnt = 1;

        int h = bombs[u][0], k = bombs[u][1], r = bombs[u][2];

        for(int i = 0; i < n; i++) {
            if(!isVisited[i]) {
                long long dx = bombs[i][0] - h;
                long long dy = bombs[i][1] - k;
                long long dist = dx * dx + dy * dy;

                if(dist <= 1LL * r * r) {
                    cnt += dfs(bombs, isVisited, i);
                }
            }
        }
        return cnt;
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            vector<bool> isVisited(n, false); // reset for each start
            maxi = max(maxi, dfs(bombs, isVisited, i));
        }
        return maxi;
    }
};