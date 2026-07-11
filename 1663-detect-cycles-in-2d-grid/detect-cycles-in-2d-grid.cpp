class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int m,n;

    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis,
             int i, int j, int ni, int nj){
        if(i<0||j<0||i>=m||j>=n) return false;

        vis[i][j]=true;

        for(auto d:dir){
            int x=i+d[0];
            int y=j+d[1];

            if(x>=0&&y>=0&&x<m&&y<n&&grid[x][y]==grid[i][j]){
                if(!vis[x][y]){
                    if(dfs(grid,vis,x,y,i,j))
                        return true;
                }
                else if(!(x==ni&&y==nj)){
                    return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();

        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && dfs(grid,vis,i,j,-1,-1))
                    return true;
            }
        }
        return false;
    }
};