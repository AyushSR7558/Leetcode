class Solution {
private:
    vector<vector<int>> adjList(vector<vector<int>> e, int v) {
        int n = e.size();
        vector<vector<int>> V(v);
        for(int i = 0; i < n; i++) {
            V[e[i][1]].push_back(e[i][0]);
        }
        return V;
    }

    bool dfs(vector<vector<int>>& adjList,vector<bool>& visited, vector<bool>& prevVisited, int indx) {
        visited[indx] = true;
        prevVisited[indx] = true;

        for(int edge : adjList[indx]) {
            if(prevVisited[edge]) return true;
            if(!visited[edge]) {
                if(dfs(adjList, visited, prevVisited, edge)) return true;
            }
        }
        prevVisited[indx] = false;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // We have to find if there is cycle or not
        /*
            * DFS :- Intution
            * BFS :- Kahan's Algorithm
        */

        vector<vector<int>> list = adjList(prerequisites, numCourses);
        vector<bool> visited(numCourses, false), prevVisited(numCourses, false);
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                if(dfs(list, visited, prevVisited, i)){
                    return false;
                }
            }
        }
        return true;
    }
};