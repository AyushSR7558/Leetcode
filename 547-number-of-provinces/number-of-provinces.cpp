class Solution {
private:
    void bfsTraversal(vector<vector<int>>& isConnected, vector<bool>& visited, int stNode){
        queue<int> q;
        int n = isConnected.size();
        q.push(stNode);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i = 0; i < n; i++){
                if((isConnected[node][i] > 0) && (!visited[i])){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> isVisited(n,false);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(isVisited[i]) continue;
            ans++;
            bfsTraversal(isConnected, isVisited, i);
        }
        return ans;
    }
};