class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x)
            parent[x] = find(parent[x], parent);
        return parent[x];
    }

    void unite(int a, int b, vector<int>& parent, vector<int>& rank) {
        int pa = find(a, parent);
        int pb = find(b, parent);

        if (pa == pb) return;

        if (rank[pa] < rank[pb]) {
            parent[pa] = pb;
        } else if (rank[pb] < rank[pa]) {
            parent[pb] = pa;
        } else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1), rank(n + 1, 0);

        for (int i = 1; i <= n; i++) parent[i] = i;

        for (auto &e : edges) {
            int u = e[0], v = e[1];

            if (find(u, parent) == find(v, parent)) {
                return e; // redundant
            }

            unite(u, v, parent, rank);
        }

        return {};
    }
};