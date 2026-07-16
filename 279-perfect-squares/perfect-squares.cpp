class Solution {
public:
    int numSquares(int n) {
        int newNum=(int)(sqrt(n));
        newNum*=newNum;
        vector<int> nums;
        for(int i=1;i<=newNum;i++){
            nums.push_back(i*i);
        }
        vector<int> dp(n+1, INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(auto num: nums){
                if(i>=num&&dp[i-num]!=INT_MAX){
                    dp[i]=min(dp[i], dp[i-num]+1);
                }
            }
        }
        return dp[n];
    }
};