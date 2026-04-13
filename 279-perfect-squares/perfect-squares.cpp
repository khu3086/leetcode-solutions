class Solution {
public:
    int numSquares(int n) {
        int num=(int)sqrt(n);
        vector<int> mynums;
        for(int i=1;i<=num;i++) mynums.push_back(i*i);
        vector<int> dp(n+1, INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(auto x: mynums){
                if(i>=x&&dp[i-x]!=INT_MAX){
                    dp[i]=min(dp[i-x]+1, dp[i]);
                }
            }
        }
        return dp[n];
    }
};