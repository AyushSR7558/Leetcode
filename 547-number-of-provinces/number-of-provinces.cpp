class Solution {
private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& isVisited, int u) {
        isVisited[u] = true;
        int n = isConnected.size();

        for(int i = 0; i < n; i++) {
            if(isConnected[u][i] == 1 && !isVisited[i]) {
                dfs(isConnected, isVisited, i);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> isVisited(n, false);
        int totProvinces = 0;

        for(int i = 0; i < n; i++) {
            if(!isVisited[i]) {
                totProvinces++;
                dfs(isConnected, isVisited, i);
            }
        }

        return totProvinces;
    }
};