class Solution {
public:
    int numSquares(int n) {
        int sqrtn=(int) sqrt(n);
        vector<int> nums;
        for(int i=1;i<=sqrtn;i++) nums.push_back(i*i);
        vector<int> dp(n+1, INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(auto x: nums){
                if(i>=x&&dp[i-x]!=INT_MAX){
                    dp[i]=min(dp[i-x]+1, dp[i]);
                }
            }
        }
        return dp[n];
    }
};