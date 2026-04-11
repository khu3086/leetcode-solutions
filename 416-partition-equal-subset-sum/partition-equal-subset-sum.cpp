class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto x: nums) sum+=x;
        if(sum%2) return false;
        sum/=2; //target sum
        vector<bool> dp(sum+1, false);
        dp[0]=true;
        for(auto num: nums){
            for(int i=sum;i>=num;i--){
                dp[i]=dp[i]||dp[i-num];
            }
        }
        return dp[sum];
        
    }
};