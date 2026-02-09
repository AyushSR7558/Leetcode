class Disjoint{
    vector<int> rank;
    vector<int> parent;
    public:

    Disjoint(int n) {
        rank.resize(n, 0);
        parent.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int u) {
        if(u == parent[u]) {
            return u;
        }
        return parent[u] = findUParent(parent[u]);
    }

    bool unionByRank(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u == ulp_v) {
            return true;
        }
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        return false;
    }

    int totComponent() {
        for(int i = 0; i < parent.size(); i++) {
            findUParent(i);
        }
        unordered_set<int> st;
        for(int i = 0; i < parent.size(); i++) {
            st.insert(parent[i]);
        }
        return st.size();
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extraedges = 0;
        Disjoint a(n);

        for(int i = 0; i < connections.size(); i++) {
            int u = connections[i][0], v = connections[i][1];
            if(a.unionByRank(u, v)) extraedges++;
        }
        int tot = a.totComponent();

        if(extraedges >= tot - 1) {
            return tot - 1;
        }
        return -1;
    }
};