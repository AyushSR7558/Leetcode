class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> costMatrix(n, vector<int>(n, INT_MAX));

        for(int i = 0; i < n; i++) {
            costMatrix[i][i] = 0;
        }

        for(auto edge : edges) {
            int from = edge[0], to = edge[1], cost = edge[2];
            costMatrix[from][to] = cost;
            costMatrix[to][from] = cost;
        }

        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    costMatrix[i][j] = min(1LL * costMatrix[i][j], 1LL * costMatrix[i][k] + costMatrix[k][j]);
                }
            }
        }

        int minCities = n, val = -1;

        for(int i = 0; i < n; i++) {
            int cityCount = 0;
            for(int j = 0; j < n; j++) {
                if(costMatrix[i][j] <= distanceThreshold) {
                    cityCount++;
                }
            }
            if(cityCount <= minCities) {
                minCities = cityCount;
                val = i;
            }
        }
        return val;
    }
};