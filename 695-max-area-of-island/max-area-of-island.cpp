class Solution {
public:
    void dfs(int& maxArea, int& currArea, vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int row, int col){
        if(i<0||i>=row||j<0||j>=col||!grid[i][j]||visited[i][j]) return;
        maxArea=max(maxArea, currArea+1);
        visited[i][j] = true;
        currArea++;
        dfs(maxArea, currArea, grid, visited, i+1, j, row, col);
        dfs(maxArea,currArea, grid, visited, i-1, j, row, col);
        dfs(maxArea,currArea, grid, visited, i, j+1, row, col);
        dfs(maxArea,currArea, grid, visited, i, j-1, row, col);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int currArea=0;
        int maxArea=0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]&&!visited[i][j]){
                    currArea=0;
                    dfs(maxArea, currArea, grid, visited, i, j, row, col);
                }
            }
        }
        return maxArea;
    }
};