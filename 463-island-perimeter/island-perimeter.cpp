class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if((i>0&&grid[i-1][j]==0)||i==0) count++;
                    if((j>0&&grid[i][j-1]==0)||j==0) count++;
                    if((i+1<m&&grid[i+1][j]==0)||i==m-1) count++;
                    if((j+1<n&&grid[i][j+1]==0)||j==n-1) count++;
                }
            }
        }
        return count;
    }
};