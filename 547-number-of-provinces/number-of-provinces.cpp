class Solution {
private:
    void bfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node) {
        int n = visited.size();
        queue<int> qp;
        
        visited[node] = true;
        for(int i = 0; i < n; i++) {
            if(isConnected[node][i] && !visited[i]){
                qp.push(i);
            }
        }
        while(!qp.empty()) {
            int subNode = qp.front();
            qp.pop();
            visited[subNode] = true;
            for(int i = 0; i < n; i++) {
                if(isConnected[subNode][i] && !visited[i]) {
                    qp.push(i);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int gPro  = 0;
        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                gPro++;
                bfs(isConnected, visited, i);
            }
        }
        return gPro;
    }
};