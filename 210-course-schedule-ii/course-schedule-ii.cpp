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
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            * BFS :- kahans algorithm
        */
        vector<vector<int>> list = adjList(prerequisites, numCourses);
        vector<int> topoSort, indegree(numCourses);

        for(int i = 0; i < numCourses; i++) {
            for(int edge : list[i]) {
                indegree[edge]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int indx = q.front();
            q.pop();
            for(int edge: list[indx]) {
                indegree[edge]--;
                if(indegree[edge] == 0) q.push(edge);
            }
            topoSort.push_back(indx);
        }
        return (topoSort.size() == numCourses? topoSort: vector<int>());

    }
};