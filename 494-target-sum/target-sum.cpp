class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(auto num: nums) sum+=num;
        if (abs(target) > sum) return 0;
        int newTgt=sum+target;
        if(newTgt%2) return 0;
        newTgt/=2;
        vector<int> dp(newTgt+1, 0);
        dp[0]=1;
        for(auto num: nums){
            for(int i=newTgt;i>=num;i--){
                if(i-num>=0) dp[i]+=dp[i-num];
            }
        }
        return dp[newTgt];
    }
};