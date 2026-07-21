class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0]=grid[0][0];
        vector<vector<int>> dir={{0, -1}, {-1, 0}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(auto d: dir){
                    int x=d[0]+i;
                    int y=d[1]+j;
                    if(x>=0&&x<m&&y>=0&&y<n&&dp[x][y]!=INT_MAX){
                        dp[i][j]=min(dp[x][y]+grid[i][j], dp[i][j]);
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};