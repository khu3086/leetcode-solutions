class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m=og.size();
        int n=og[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0]=1;
        vector<vector<int>> dir={{-1, 0}, {0, -1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(auto d: dir){
                    int x=d[0]+i;
                    int y=d[1]+j;
                    if(x>=0&&x<m&&y>=0&&y<n&&og[x][y]!=1){
                        dp[i][j]+=dp[x][y];
                    }
                }
            }
        }
        if(og[m-1][n-1]==1) return 0;
        return dp[m-1][n-1];
    }
};