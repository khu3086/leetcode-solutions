class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int maxRes=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j]=1;
                }
                if(dp[i][j]&&dp[i-1][j]!=0&&dp[i][j-1]!=0&&dp[i-1][j-1]!=0){
                    dp[i][j]=dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
                maxRes=max(dp[i][j], maxRes);
            }
        }
        return maxRes*maxRes;
    }
};