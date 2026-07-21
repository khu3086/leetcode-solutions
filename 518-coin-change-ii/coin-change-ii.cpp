class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //unbounded kanpsack-> order doesnt matter process coin first
        vector<long long> dp(amount+1, 0);
        dp[0]=1;
        int MOD=1e9+7;
        for(auto coin: coins){
            for(int i=1;i<=amount;i++){
                if(i-coin>=0&&dp[i-coin]!=0){
                    dp[i]+=dp[i-coin];
                }
                if(dp[i]>1e18) dp[i]%=MOD;
            }
        }
        return dp[amount];
    }
};