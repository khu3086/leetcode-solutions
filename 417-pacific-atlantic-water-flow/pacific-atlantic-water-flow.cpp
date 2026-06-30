class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis,
             int i, int j, int row, int col) {

        vis[i][j] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < row &&
                nj >= 0 && nj < col &&
                !vis[ni][nj] &&
                heights[ni][nj] >= heights[i][j]) {

                dfs(heights, vis, ni, nj, row, col);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int row = heights.size();
        int col = heights[0].size();

        vector<vector<bool>> pacific(row, vector<bool>(col, false));
        vector<vector<bool>> atlantic(row, vector<bool>(col, false));

        // Pacific: left column
        for (int i = 0; i < row; i++)
            if (!pacific[i][0])
                dfs(heights, pacific, i, 0, row, col);

        // Pacific: top row
        for (int j = 0; j < col; j++)
            if (!pacific[0][j])
                dfs(heights, pacific, 0, j, row, col);

        // Atlantic: right column
        for (int i = 0; i < row; i++)
            if (!atlantic[i][col - 1])
                dfs(heights, atlantic, i, col - 1, row, col);

        // Atlantic: bottom row
        for (int j = 0; j < col; j++)
            if (!atlantic[row - 1][j])
                dfs(heights, atlantic, row - 1, j, row, col);

        vector<vector<int>> ans;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};