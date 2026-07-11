class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<bool>& vis, int u, unordered_set<int>& con) {
        vis[u] = true;
        con.insert(u);

        for(int v : graph[u]) {
            if(!vis[v]) {
                dfs(graph, vis, v, con);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<vector<int>> graph(n);
        int cnt = 0, m = edges.size();

        for(int i = 0; i < m; i++) {
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                unordered_set<int> con;
                dfs(graph, vis, i, con);
                bool isComplete = true;
                int sz = con.size();

                for(int i : con) {
                    unordered_set<int> temp = con;
                    temp.erase(i);
                    for(int v : graph[i]) {
                        if(con.contains(v)) {
                            temp.erase(v);
                        }
                    }
                    if(temp.size() != 0) {
                        isComplete = false;
                        break;
                    }
                }
                if(isComplete) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};