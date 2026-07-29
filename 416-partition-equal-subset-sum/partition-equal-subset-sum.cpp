class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto num: nums) sum+=num;
        if(sum%2==1) return false;
        sum/=2;
        vector<bool> dp(sum+1, false);
        dp[0]=true;
        for(auto num: nums){
            for(int i=sum;i>=num;i--){
                if(i-num>=0&&dp[i-num]) dp[i]=dp[i-num];
            }
        }
        return dp[sum];
    }
};