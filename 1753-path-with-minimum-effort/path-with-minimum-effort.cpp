class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [effort, cell] = pq.top();
            pq.pop();

            int i = cell.first;
            int j = cell.second;

            // Skip stale entries
            if (effort > dist[i][j]) continue;

            // Reached destination
            if (i == m - 1 && j == n - 1)
                return effort;

            for (auto &d : dir) {
                int x = i + d[0];
                int y = j + d[1];

                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int newEffort = max(
                        effort,
                        abs(heights[i][j] - heights[x][y])
                    );

                    if (newEffort < dist[x][y]) {
                        dist[x][y] = newEffort;
                        pq.push({newEffort, {x, y}});
                    }
                }
            }
        }

        return 0;
    }
};