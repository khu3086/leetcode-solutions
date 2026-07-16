class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> coins;
        int maxCoin=numWays.size();
        int minCoin=1;
        int n=maxCoin;
        vector<int> dp(n+1, 0);
        for(int i=1;i<=n;i++){
            if(numWays[i-1]>=0){
                //check 0 till i-1
                //i==4
                vector<int> miniDp(i+1, 0);
                miniDp[0]=1;
                for(auto x: coins){
                    for(int j=x;j<=i;j++){
                        if(j>=x&&miniDp[j-x]!=0){
                            miniDp[j]+=miniDp[j-x];
                        }
                    }
                }
                if (miniDp[i] == numWays[i-1]){}
                else if(numWays[i-1]-miniDp[i]==1){
                    dp[i]=1;
                    coins.push_back(i);
                }
                else return {};
            }
        }
        return coins;
    }
};