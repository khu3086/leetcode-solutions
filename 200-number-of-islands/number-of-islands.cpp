class Solution {
public:
    void dfs(vector<vector<char>>& grid,
             vector<vector<bool>>& visited,
             int i, int j, int row, int col){

        if(i<0 || i>=row || j<0 || j>=col ||
           grid[i][j] == '0' || visited[i][j])
            return;

        visited[i][j] = true;

        dfs(grid, visited, i+1, j, row, col);
        dfs(grid, visited, i-1, j, row, col);
        dfs(grid, visited, i, j+1, row, col);
        dfs(grid, visited, i, j-1, row, col);
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int count = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid, visited, i, j, row, col);
                    count++;
                }
            }
        }
        return count;
    }
};