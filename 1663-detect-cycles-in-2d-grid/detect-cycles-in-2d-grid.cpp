class Solution {
public:
    bool dfs(vector<vector<vector<pair<int,int>>>>& adj,
             int i, int j,
             int pi, int pj,
             vector<vector<bool>>& vis) {

        vis[i][j] = true;

        for (auto nxt : adj[i][j]) {
            int ni = nxt.first;
            int nj = nxt.second;

            if (!vis[ni][nj]) {
                if (dfs(adj, ni, nj, i, j, vis))
                    return true;
            }
            else if (ni != pi || nj != pj) {
                return true;
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<pair<int,int>>>> adj(
            m, vector<vector<pair<int,int>>>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i > 0 && grid[i-1][j] == grid[i][j])
                    adj[i][j].push_back({i-1, j});

                if (i < m-1 && grid[i+1][j] == grid[i][j])
                    adj[i][j].push_back({i+1, j});

                if (j > 0 && grid[i][j-1] == grid[i][j])
                    adj[i][j].push_back({i, j-1});

                if (j < n-1 && grid[i][j+1] == grid[i][j])
                    adj[i][j].push_back({i, j+1});
            }
        }

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    if (dfs(adj, i, j, -1, -1, vis))
                        return true;
                }
            }
        }

        return false;
    }
};