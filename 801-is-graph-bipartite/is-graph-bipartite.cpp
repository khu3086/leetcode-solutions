class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int curr) {
        for (int v : graph[curr]) {
            if (color[v] == color[curr])
                return false;

            if (color[v] == -1) {
                color[v] = !color[curr];
                if (!dfs(graph, color, v))
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                if (!dfs(graph, color, i))
                    return false;
            }
        }

        return true;
    }
};