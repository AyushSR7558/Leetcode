class Solution {
private:
    int dfs(vector<vector<int>>& adjList, vector<bool>& visited, int u) {
        int countEdges = 0, edges = 0;
        visited[u] = true;
        for(int v : adjList[u]) {
            countEdges++;
            if(!visited[v]) {
                countEdges += dfs(adjList, visited, v);
                edges+= 2;
            }
        }

        return countEdges - edges;
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
         vector<bool> visited(n, false);
        vector<vector<int>> adjList(n);
        int countComponent = 0, extraEdges = 0;

        for(int i = 0; i < connections.size(); i++) {
            int u = connections[i][0], v = connections[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                extraEdges += dfs(adjList, visited, i) / 2;
                countComponent++;
            }
        }

        if(extraEdges >= countComponent - 1) {
            return countComponent - 1;
        }


        return -1;
    }
};