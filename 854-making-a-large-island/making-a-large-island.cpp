class Disjoint {
public:
    vector<int> size;
    vector<int> parent;

public:
    Disjoint(int n) {
        size.resize(n, 1);      // Each node size = 1
        parent.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int u) {
        if(u == parent[u]) return u;
        return parent[u] = findUParent(parent[u]);  // Path compression
    }

    void unionBySize(int u, int v) {
        int upu = findUParent(u);
        int upv = findUParent(v);

        if(upu == upv) return;

        if(size[upu] < size[upv]) {
            parent[upu] = upv;
            size[upv] += size[upu];
        } 
        else {
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        Disjoint component(n * n);

        vector<pair<int,int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!grid[i][j]) continue;
                int node = i * n + j;
                for(int k = 0; k < 4; k++) {
                    int x = i + dir[k].first, y = j + dir[k].second;
                    if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y]) {
                        int adjNode = x * n + y;
                        component.unionBySize(node, adjNode);
                    }
                }
            }
        }
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) continue;
                unordered_set<int> Uparent;
                int node = i * n + j;
                int count = 1;
                for(int k = 0; k < 4; k++) {
                    int x = i + dir[k].first, y = j + dir[k].second;
                    if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y]) {
                        int adjNode = x * n + y;
                        Uparent.insert(component.findUParent(adjNode));
                    }
                }
                for(int u : Uparent) {
                    count += component.size[u];
                }
                maxi = max(maxi, count);
            }
        }
        for(int i = 0; i < n * n; i++) {
            if(component.parent[i] == i) {
                maxi = max(component.size[i], maxi);
            }
        }
        return maxi;
    }
};