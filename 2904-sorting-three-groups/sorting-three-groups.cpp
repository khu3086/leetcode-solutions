class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<=nums[i]){
                    dp[i]=max(dp[j]+1, dp[i]);
                }
            }
        }
        int maxLen=INT_MIN;
        for(auto m: dp) maxLen=max(maxLen, m);
        return n-maxLen;
    }
};