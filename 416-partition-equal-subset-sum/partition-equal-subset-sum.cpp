class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto num: nums) sum+=num;
        if(sum%2) return false;
        sum/=2;
        vector<bool> dp(sum+1, 0);
        dp[0]=true;
        for(auto num: nums){
            for(int i=sum;i>=num;i--){
                if(i>=num){
                    dp[i]=dp[i]||dp[i-num];
                }
            }
        }
        return dp[sum];
    }
};