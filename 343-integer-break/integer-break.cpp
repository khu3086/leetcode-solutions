class Solution {
public:
    int integerBreak(int n) {
        if(n==2||n==3) return n-1;
        vector<int> dp(n+2, 0);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n+1;i++){
            for(int j=0;j<=i;j++){
                dp[i]=max(dp[i], dp[i-j]*j);
            }
        }
        return dp[n+1];
    }
};