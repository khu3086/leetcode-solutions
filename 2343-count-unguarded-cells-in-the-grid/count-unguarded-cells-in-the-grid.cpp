class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); // 0 = empty, 1 = guard, 2 = wall, 3 = guarded
        
        for (auto &g : guards) grid[g[0]][g[1]] = 1;
        for (auto &w : walls) grid[w[0]][w[1]] = 2;

        // simulate each guard's line of sight
        for (auto &g : guards) {
            int row = g[0], col = g[1];

            // up
            for (int r = row - 1; r >= 0; r--) {
                if (grid[r][col] == 1 || grid[r][col] == 2) break;
                if (grid[r][col] == 0) grid[r][col] = 3;
            }
            // down
            for (int r = row + 1; r < m; r++) {
                if (grid[r][col] == 1 || grid[r][col] == 2) break;
                if (grid[r][col] == 0) grid[r][col] = 3;
            }
            // left
            for (int c = col - 1; c >= 0; c--) {
                if (grid[row][c] == 1 || grid[row][c] == 2) break;
                if (grid[row][c] == 0) grid[row][c] = 3;
            }
            // right
            for (int c = col + 1; c < n; c++) {
                if (grid[row][c] == 1 || grid[row][c] == 2) break;
                if (grid[row][c] == 0) grid[row][c] = 3;
            }
        }

        // count unguarded cells
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0)
                    count++;

        return count;
    }
};
