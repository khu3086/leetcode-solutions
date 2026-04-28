class Solution {
public:
    void dfs(vector<vector<int>>& heights, int row, int col, int i, int j, vector<vector<bool>>& vis){
         if(i<0 || i>=row || j<0 || j>=col || vis[i][j]) return;
        vis[i][j]=true;
        if(i>0&&heights[i-1][j]>=heights[i][j]){
            dfs(heights, row, col, i-1, j, vis);
        }
        if(j>0&&heights[i][j-1]>=heights[i][j]){
            dfs(heights, row, col, i, j-1, vis);
        }
        if(i<row-1&&heights[i+1][j]>=heights[i][j]){
            dfs(heights, row, col, i+1, j, vis);
        }
        if(j<col-1&&heights[i][j+1]>=heights[i][j]){
            dfs(heights, row, col, i, j+1, vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //dfs from border elements and check whether it can reach the other side
        //mark all path elements as true if it can
        int row=heights.size();
        int col=heights[0].size();
        vector<vector<bool>> pacific(row, vector<bool>(col, false));
        vector<vector<bool>> atlantic(row, vector<bool>(col, false));
        for(int i=0;i<col;i++) {
            dfs(heights, row, col, 0, i, pacific);
        }
        for(int i=0;i<row;i++){
            dfs(heights, row, col, i, 0, pacific);
        } 
        for(int i=0;i<col;i++) {
            dfs(heights, row, col, row-1, i, atlantic);
        }
        for(int i=0;i<row;i++){
            dfs(heights, row, col, i, col-1, atlantic);
        } 
        vector<vector<int>> ans;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(atlantic[i][j]&&pacific[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};